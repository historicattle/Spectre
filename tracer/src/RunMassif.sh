#!/bash/bin
set +x

valgrind $1 --tool=massif --massif-out-file="../output/MassifOut.log" --stacks=yes --detailed-freq=1 \
--time-unit=ms --massif-heap=yes --massif-heap-extra=yes --massif-heap-extra-freq=1 \
--massif-heap-extra-time-unit=ms --massif-heap-extra-verbose=yes --massif-heap-extra-freq=1
"$@" 