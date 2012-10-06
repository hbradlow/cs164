.PHONY: check clean really-clean

APYC = ../apyc

GOODTEST = python test-proj1

BADTEST = python test-proj1 --errors

ALL_CORRECT_TESTS = `find correct -name "*.py"`
ALL_ERROR_TESTS = `find error -name "*.py"`

check:
	@echo
	@echo Testing correct programs...
	@rm -f errflag
	@-$(GOODTEST) --compiler=$(APYC) $(ALL_CORRECT_TESTS) || touch errflag
	@echo
	@echo Testing erroneous programs...
	@-$(BADTEST) --compiler=$(APYC) $(ALL_ERROR_TESTS) || touch errflag
	@echo
	@if test -f errflag; then code=1; else code=0; fi; \
        rm -f errflag; exit $$code

clean:
	echo $(ALL_TESTS)
	$(RM) errflag *~ */*~

really-clean: clean
