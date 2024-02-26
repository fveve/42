#include "../include/minishell.h"

int main (int argc, char **argv, char **envp)
{
	t_cmd *cmd;

	argc = argc;
	printf("sdsdsd");
	cmd = extract_tab(argv, envp);
	free_cmd(cmd);
	return 0;
}