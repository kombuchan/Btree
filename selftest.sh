#! /bin/bash

for i in {1..100}
do
    echo ===== START $i TESTING ===== >> results.txt
    echo ===== START $i TESTING ===== >> resultcomp.txt
    ./testgenerator
    ./args1.sh > a.txt
    ./args2.sh > b.txt
    diff a.txt b.txt >> results.txt
    echo $i input >> inputs.txt
    cat BTreeTest.txt >> inputs.txt
    echo >> inputs.txt
    cat args1.sh >> inputs.txt
    echo >> inputs.txt
    echo ===== END $i TESTING ===== >> results.txt
    echo ===== END $i TESTING ===== >> resultcomp.txt
    if [ `expr $i % 10` -eq 0 ]
    then
        echo $i
    fi
done
diff results.txt resultcomp.txt > finalresult.txt
cat finalresult.txt