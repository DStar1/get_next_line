cp -R ../../libft libft/
cp ../../get_next_line.* .
make -C libft
for i in $(echo "1 4 100 2056"); do
	rm -f *.o test_gnl
	sed -i.bak "s/^# *define BUFF_SIZE[\t ]*[0-9]*$/# define BUFF_SIZE $i/g" get_next_line.h
	rm -f get_next_line.h.bak
	make
	./test_gnl
	diff -U3 test1.{out,in} | grep -E "^(\-|\+)"
done

