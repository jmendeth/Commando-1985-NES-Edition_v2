#!/bin/bash
# collect assets used in code, save into file
# copy those files into assets/

set -e

grep -oE '"Resources\/[^"]+"' -rh | sort -u | python -c $'import sys\nfor l in sys.stdin: print eval(l)' > assets.txt

rm -rf assets 2> /dev/null

while read p; do
  ls "$p" || continue
  mkdir -p assets/"$(dirname "$p")"
  cp "$p" assets/"$p"
done < assets.txt
