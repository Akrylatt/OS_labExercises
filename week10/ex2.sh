mkdir week01
cd week01
echo adel > file.txt
cd ..
cd week10
echo week10 > _ex2.txt
cd ..
link file.txt ../_ex2.txt
find . -inum 259 
find . -inum 259 -exec rm {} \;
find . -inum 259

