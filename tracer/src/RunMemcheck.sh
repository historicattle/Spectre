#!/bin/bash
set +x

valgrind $1 --tool=memcheck --leak-check=full --track-origins=yes --show-leak-kinds=all --error-exitcode=1 \
--log-file="../output/MemcheckOut.txt" "$@"
