all:
	@echo "Building Spring 12 Planet Engine Cracker!"
	@echo "正在准备春节12响程序"
	@mkdir -p ./build
	@gcc -c ./twelve_biubiu.c -o ./build/twelve_biubiu.o
	@echo "Build Complete!"
clean:
	rm -rfv ./build/
