begin
decl
int arr[20];
int i, j, n;
int count;
int temp;
enddecl

write("Enter count\n");
read(count);
i = 0;
while(i < count) do
    read(arr[i]);
    write(arr[i]);
    i = i + 1;
endwhile;

i = 0;
while(i < count) do
    write(arr[i]);
    i = i + 1;
endwhile;

i = 0;

while(i < count) do
    j = 0;
    while(j < count - i - 1) do 
        if( arr[j] > arr [j+1]) then
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
        endif;
        j = j + 1;
    endwhile; 
    i = i + 1;
endwhile;

i = 0;
while(i < count) do
    write(arr[i]);
    i = i + 1;
endwhile;

end;