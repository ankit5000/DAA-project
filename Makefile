default:
	@echo “Compiling RANKFRAUD solution ..."
	@g++ -o output rankfraud.cpp
	@echo “Compilation Successful.”
	@echo “Now executing ...”
	@./output

