.PHONY: clean All

All:
	@echo "----------Building project:[ solution - Debug ]----------"
	@cd "solution" && "$(MAKE)" -f  "solution.mk"
clean:
	@echo "----------Cleaning project:[ solution - Debug ]----------"
	@cd "solution" && "$(MAKE)" -f  "solution.mk" clean
