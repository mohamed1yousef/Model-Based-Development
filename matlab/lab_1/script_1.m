%part1
matrixA =[3 2 1;6 5 4;9 8 7];
matrixB =[12 11 10;15 14 13;18 17 16];
matrixSum = matrixA + matrixB;
disp('matrixSum = ')
disp(matrixSum)
%part2
rowVector =1:5;
columnVector =(6:10)';
horizontalConcat = horzcat(rowVector,columnVector.');
disp('horizontalConcat = ')
disp(horizontalConcat)
%part3
originalMatrix =rand(2);
repeatedMatrix = repmat(originalMatrix,2,2);
disp('repeatedMatrix = ')
disp(repeatedMatrix)
%part4
identityMatrix =eye(3);
matrixProduct = identityMatrix .* matrixA;
disp('matrixProduct = ')
disp(matrixProduct)
