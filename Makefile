TARGET = main.out

HDRS = \
	   include


SRC = src/app.cpp\
			src/db.cpp\
			src/main.cpp\
			src/row_writer.cpp

main:
	c++ ${SRC} $(addprefix -I,$(HDRS)) -o ${TARGET}
clean:
	rm ${TARGET}
