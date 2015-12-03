#! /usr/bin/env bash
echo start test
echo test1;
grep -x -v hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out1 
./my_grep -x -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out1 -
echo test2;
grep -x hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out2 
./my_grep -x hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out2 - 
echo test3;
grep hello OneLine.txt 		> ~matansagi/c_lab/ex2/grep_tests/out3 
./my_grep hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out3 -
echo test4;
grep -c hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out4 
./my_grep -c hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out4 -
echo test5;
grep -c -v hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out5 
./my_grep -c -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out5 -
echo test6;
grep -n -v hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out6 
./my_grep -n -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out6 -
echo test7;
grep -n  hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out7 
./my_grep -n  hello OneLine.txt |   diff ~matansagi/c_lab/ex2/grep_tests/out7 -
echo test8;
grep -i -n HEllo OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out8 
./my_grep -i -n HEllo OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out8 -
echo test9;
grep -i -n HoW OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out9 
./my_grep -i -n HoW OneLine.txt |   diff ~matansagi/c_lab/ex2/grep_tests/out9 -
echo test10;
grep -i -n -v HoW OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out10
./my_grep -i -n -v HoW OneLine.txt |diff ~matansagi/c_lab/ex2/grep_tests/out10 -
echo test11;
grep -b -x -v hello OneLine.txt > ~matansagi/c_lab/ex2/grep_tests/out11
./my_grep -b -x -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out11 -
echo test12;
grep -b -x hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out12  
./my_grep -b -x hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out12 -  
echo test13;
grep -b hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out13
./my_grep -b hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out13 -
echo test14;
grep -b -c hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out14
./my_grep -b -c hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out14 -
echo test15;
grep -b -c -v hello OneLine.txt > ~matansagi/c_lab/ex2/grep_tests/out15
./my_grep -b -c -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out15 -
echo test16;
grep -b -n -v hello OneLine.txt > ~matansagi/c_lab/ex2/grep_tests/out16
./my_grep -b -n -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out16 -
echo test17;
grep -b -n  hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out17 
./my_grep -b -n  hello OneLine.txt |   diff ~matansagi/c_lab/ex2/grep_tests/out17 - 
echo test18;
grep -b -i -n HEllo OneLine.txt > ~matansagi/c_lab/ex2/grep_tests/out18
./my_grep -b -i -n HEllo OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out18 -
echo test19;
grep -b -i -n HoW OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out19
./my_grep -b -i -n HoW OneLine.txt |   diff ~matansagi/c_lab/ex2/grep_tests/out19 -
echo test20;
grep -b -i -n -v HoW OneLine.txt> ~matansagi/c_lab/ex2/grep_tests/out20
./my_grep -b -i -n -v HoW OneLine.txt |diff ~matansagi/c_lab/ex2/grep_tests/out20 -
echo test21;
grep -A 3 -b -x -v hello OneLine.txt > ~matansagi/c_lab/ex2/grep_tests/out21
./my_grep -A 3 -b -x -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out21 -
echo test22;
grep -A 3 -b -x hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out22  
./my_grep -A 3 -b -x hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out22 -  
echo test23;
grep -A 1 -b hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out23
./my_grep -A 1 -b hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out23 -
echo test24;
grep -A 1 -b -c hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out24
./my_grep -A 1 -b -c hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out24 -
echo test25;
grep -A 3 -b -c -v hello OneLine.txt > ~matansagi/c_lab/ex2/grep_tests/out25
./my_grep -A 3 -b -c -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out25 -
echo test26;
grep -A 2 -b -n -v hello OneLine.txt > ~matansagi/c_lab/ex2/grep_tests/out26
./my_grep -A 2 -b -n -v hello OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out26 -
echo test27;
grep -A 3 -b -n  hello OneLine.txt 	> ~matansagi/c_lab/ex2/grep_tests/out27 
./my_grep -A 3 -b -n  hello OneLine.txt |   diff ~matansagi/c_lab/ex2/grep_tests/out27 - 
echo test28;
grep -A 4 -b -i -n HEllo OneLine.txt > ~matansagi/c_lab/ex2/grep_tests/out28
./my_grep -A 4 -b -i -n HEllo OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out28 -
echo test29;
grep -A 5 -b -i -n HoW OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out29
./my_grep -A 5 -b -i -n HoW OneLine.txt |   diff ~matansagi/c_lab/ex2/grep_tests/out29 -
echo test30;
grep -A 6 -b -i -n -v HoW OneLine.txt> ~matansagi/c_lab/ex2/grep_tests/out30
./my_grep -A 6 -b -i -n -v HoW OneLine.txt |diff ~matansagi/c_lab/ex2/grep_tests/out30 -
echo test31;
grep -v -x -c -A 6 -b -i -n -v HoW OneLine.txt> ~matansagi/c_lab/ex2/grep_tests/out31
./my_grep -v -x -c -A 6 -b -i -n -v HoW OneLine.txt |diff ~matansagi/c_lab/ex2/grep_tests/out31 -
echo test32
grep -E "(none|Line)\..xt-[A-I]" OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out32
./my_grep -E "(none|Line)\..xt-[A-I]" OneLine.txt | diff ~matansagi/c_lab/ex2/grep_tests/out32 -
echo test33
grep -n -b -i -E "(none|lINe)\..Xt-[a-h]" OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out33
./my_grep -n -b -i -E "(none|lINe)\..Xt-[a-h]" OneLine.txt	| diff ~matansagi/c_lab/ex2/grep_tests/out33 -
echo test34
grep -n -b -i -A 3 -E "(|lINe)\..Xt-[a-h]" OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out34
./my_grep -n -b -i -A 3 -E "(|lINe)\..Xt-[a-h]" OneLine.txt	|diff ~matansagi/c_lab/ex2/grep_tests/out34 -
echo test35 
grep -n -b -v -i -A 3 -E "(|lINe)\..Xt-[a-h]" OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out35
./my_grep -n -b -v -i -A 3 -E "(|lINe)\..Xt-[a-h]" OneLine.txt	|diff ~matansagi/c_lab/ex2/grep_tests/out35 -
echo test36
grep -n -b -i -A 8 -E "(b|g).[a-h]" OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out36
./my_grep -n -b -i -A 8 -E "(b|g).[a-h]" OneLine.txt      |diff ~matansagi/c_lab/ex2/grep_tests/out36 -
echo test37
grep -c -i -A 8 -E "(b|g).[a-h]" OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out37
./my_grep -c -i -A 8 -E "(b|g).[a-h]" OneLine.txt      |diff ~matansagi/c_lab/ex2/grep_tests/out37 -
echo test38
grep -v -c -n -b -i -A 8 -E "(b|g).[a-h]" OneLine.txt	> ~matansagi/c_lab/ex2/grep_tests/out38
./my_grep -v -c -n -b -i -A 8 -E "(b|g).[a-h]" OneLine.txt      |diff ~matansagi/c_lab/ex2/grep_tests/out38 -
