echo The following instructions were found:
echo
awk -F '\t+' '{if (match($3, /[a-z]+/, m)) print m[0]
		if ($3 ~ /repz retq/) print "retq"}' $1 | awk NF | sort | uniq -c | awk '{print $0 " executions."}'
echo
echo The following functions have been found:
echo
awk '/<[a-zA-Z]+>/ {print $0}' $1 | tr "<>:" "   " | awk '{if ($2 !~ /[0-9]+/) print $2 " is in memory address: " $1}'

