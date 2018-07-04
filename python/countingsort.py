#!/usr/bin/python

"""Sorts CLI arguments using counting sort"""

import itertools
import sys


def sort(array):
    """Sorts a list of numbers using counting sort"""
    greatest = max(array)
    counts = [0] * (greatest + 1)
    outputs = []
    for i in array:
        counts[i] += 1
    for index, i in enumerate(counts):
        for _ in itertools.repeat(1, i):
            outputs.append(index)
    return outputs


def main():
    """Program entry point"""
    inputs = list(map(int, sys.argv[1:]))
    outputs = sort(inputs)
    for i in outputs:
        print(i, end=' ')
    print('')


if __name__ == '__main__':
    main()
