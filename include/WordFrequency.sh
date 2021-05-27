cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r -n | awk '{print $2, $1}'
