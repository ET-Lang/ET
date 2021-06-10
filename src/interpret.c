//
// Created by max on 6/9/21.
//

#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "lexer.h"
#include "token.h"
#include "parser.h"
#include "file.h"

#include "interpret.h"

int interpret_source(char* source)
{
	debug("interpret_source");
	debug("interpret_source: %s", source);

	// https://www.freebsd.org/cgi/man.cgi?query=sysexits&apropos=0&sektion=0&manpath=FreeBSD+4.3-RELEASE&format=html
	int ret = EXIT_SUCCESS;

	lexer_init(source);
//	lexer_scan();

	Token t;
	for(;;) {
		t = lexer_scan();
//		debug("print_token: %s", token_name(t.type));
		if(t.type == TOKEN_EOF) break;
	}

	parser_init();
	parser_scan();

	return ret;
}

int interpret_file(const char* path)
{
	debug("interpret_file");
	debug("interpret_file: %s", path);

	char* source = file_reads(path);
	int ret = interpret_source(source);
	free(source);
	return ret;
}
