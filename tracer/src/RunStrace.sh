#!/bin/bash
set +x

strace $1 -o "../output/StraceOut.log" -f -ttt --verbose --trace=%memory "$@"