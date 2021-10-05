while true
do
	comm=$(g++ -std=c++11 test.cpp ; ./a.out > 1.in ; g++ -std=c++11 1.cpp -g ; ./a.out < 1.in > 1.out ; g++ -std=c++11 -g 2.cpp ; ./a.out < 1.in > 2.out ;)
#	sort 1.out > 11.out
#	sort 2.out > 22.out
#	cat 1.out
	file1=1.out
	file2=2.out
	if !(cmp -s "$file1" "$file2")
	then
		echo "Input file is"
		cat 1.in
		echo
		echo "Output of 1.cpp is"
		cat 1.out
		echo "Output of 3.cpp is"
		cat 2.out
		break;
	fi
done
