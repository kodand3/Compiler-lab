
begin
decl
int m1 [2][2],m2[2][2];
int i,j;
enddecl
i = 0;
j = 0;
while (i < 2) do
    j = 0;
    while( j < 2 ) do
        read(m1[i][j]);
        read(m2[i][j]);

        j = j + 1;
    endwhile;
    i = i + 1;
endwhile;

i = 0;
while (i < 2) do
    j = 0;
    while( j < 2 ) do
        write(m1[i][j] + m2[i][j]);

        j = j + 1;
    endwhile;
    i = i + 1;
endwhile;
end;