if [ ! -f num.txt ]; then
echo 0 > num.txt
fi

counter=1 # 100

while [ $counter -lt 100 ];
do
  if [! ln num.txt num.lock]; then
    echo 0 > $lck
    LAST = 'tail -1 num.txt'
    NEXT = 'expr 1 + ${LASTNUMBER}'

    echo $NEXT >> num.txt
    rm num.lock

done




