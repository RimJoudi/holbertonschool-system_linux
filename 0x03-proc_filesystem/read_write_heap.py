#!/usr/bin/python3

"""
script that finds a string in the heap of a running process, and replaces it.
"""
import sys


def init():
    """
    Init
    """
    if len(sys.argv) != 4:
        print('Usage: read_write_heap.py pid search_string replace_string')
        exit(1)
    pid = sys.argv[1]
    search_string = sys.argv[2]
    replace_string = sys.argv[3]

    try:
        maps_file = open('/proc/{}/maps'.format(pid), 'r')
    except Exception as e:
        print(e)
        exit(1)

    try:
        mem_file = open('/proc/{}/mem'.format(pid), 'r+b', 0)
    except Exception as e:
        maps_file.close()
        print(e)
        exit(1)

    for line in maps_file.readlines():
        line_split = line.split()
        if '[heap]' in line_split:
            mem = line_split[0].split('-')
            mem_start = int(mem[0], 16)
            mem_end = int(mem[1], 16)
            mem_file.seek(mem_start)
            string_space = mem_file.read(mem_end - mem_start)
            string_position = string_space.find(str.encode(search_string))

            if string_position == -1:
                break

            mem_file.seek(mem_start + string_position)
            mem_file.write(str.encode(replace_string) + b'\x00')
            break

    mem_file.close()
    maps_file.close()

if __name__ == '__main__':
    init()
