#!/bin/bash

echo "Disk Partitions:"
echo "================"
df -h

echo ""
echo "Free Space:"
echo "==========="
df -h --total

echo ""
echo "Disk Usage:"
echo "==========="
du -sh /*