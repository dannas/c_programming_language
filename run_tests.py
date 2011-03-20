#!/usr/bin/env python

import os
import re
import shlex
import subprocess
import sys

def usage_and_exit(msg):
    if msg:
        sys.stderr.write('%s\n\n' % msg)
    sys.stderr.write(
    'USAGE: %s BINARY [OUTPUT_FILE]\n'
    '  stdout will be used if OUTPUT_FILE is not provided\n'
    % os.path.basename(sys.argv[0]))
    sys.stderr.flush()
    sys.exit(1)

class TextColors:
    '''Some ANSI terminal constants for output color'''
    ENDC = '\033[0;m'
    FAILURE = '\033[1;31m'
    SUCCESS = '\033[1;32m'


class Processor:
    re_command = re.compile(r'  \$ (.*)')
    re_output = re.compile(r'  (.*)')
    re_comments = re.compile(r'^[^ ]{,2}.*')
    re_empty_line = re.compile(r'(^$)')

    def _sub_command(self, match):
        self.expected == []
        self.actual = []
        self.cmd = ' '.join(shlex.split(match.group(1)))

        p = subprocess.Popen(self.cmd,
                             stdout=subprocess.PIPE,
                             stderr=subprocess.STDOUT,
                             shell=True)

        # stderr is redirected to stdout
        (stdout, unused_stderr) = p.communicate()
        p.wait()
        self.actual = stdout.split('\n')

    def _sub_output(self, match):
        self.expected.append(match.group(1))

    def _sub_empty_line(self, match):
        if len(self.actual) == 0 and len(self.expected) == 0:
            return

        self.expected.append('')

        if len(self.expected) != len(self.actual):
            self.output.write(TextColors.FAILURE + "FAIL" + TextColors.ENDC + ": %s\n" % self.cmd)
            self.expected = []
            self.actual = []
            return

        n = [ i for i, j in zip(self.expected, self.actual) if i == j]

        if len(n) != len(self.expected):
            self.output.write(TextColors.FAILURE + "FAIL" + TextColors.ENDC + ": %s\n" % self.cmd)
            self.expected = []
            self.actual = []
            return

        self.output.write(TextColors.SUCCESS + "PASS " + TextColors.ENDC + ": %s\n" % self.cmd)
        self.expected = []
        self.actual = []

    def __init__(self, output):
        self.directives = {
            self.re_command    :    self._sub_command,
            self.re_output     :    self._sub_output,
            self.re_empty_line :    self._sub_empty_line,
        }
        self.actual = []
        self.expected = []
        self.cmd = []
        self.output = output

    def process_file(self, input):
        #input = self.re_comments.sub('', input)

        for line in input.split('\n'):
            for regex, handler in self.directives.iteritems():
                match = regex.match(line)
                if match:
                    handler(match)
                    break

def main(input_filepath, output):
    filename = input_filepath
    input = open(filename, "r").read()

    proc = Processor(output)
    proc.process_file(input)

if __name__ == '__main__':
    if len(sys.argv) < 2 or len(sys.argv) > 3:
        usage_and_exit('Incorrect number of arguments')

    input_filepath = sys.argv[1]

    if len(sys.argv) > 2:
        output_file = open(sys.argv[2], "w")
    else:
        output_file = sys.stdout

    main(input_filepath, output_file)
