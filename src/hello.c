#include <config.h>
#include <stdio.h>

static const char greet[] = "Hello, world!";

char *greeting() {
    return greet;
}

void
hello(void)
{
    puts( greeting() );
    puts("This is " PACKAGE_STRING ".");
}
