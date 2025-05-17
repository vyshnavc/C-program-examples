/*implement watch command using parent & child process logic.*/
#include"../inc/watch.h"
void main(int argc,char *argv[])
{
	int n=2;
	if(argc<=1||argc>=5)
	{
		printf("\nwatch <option> <command>\n");
		return;
	}
	if(fork()==0)
	{ 
		//		printf("child = %d",getpid());
		while(1)
		{      
                        system("clear");
			if(argc==2&&argv[1][1]!='h')
			{
				printf("every %ds : %s\t\t\t\t\t\t\t\t\t\t\t\t\t",n,argv[1]);
				fflush(stdout);
				system("date");
				printf("\n");
				system(argv[1]);
			}
			else
			{
				if(argv[1][0]!='-')
				{       
                                        if(argv[1][0]=='n')
					printf("every %ds : %s %s %s\t\t\t\t\t\t\t\t\t\t\t\t",n,argv[1],argv[2],argv[3]);
                                        else if(argv[1][0]=='h')
					printf("every %ds : %s\t\t\t\t\t\t\t\t\t\t\t\t\t",n,argv[1]);
                                        else
					printf("every %ds : %s %s\t\t\t\t\t\t\t\t\t\t\t\t\t",n,argv[1],argv[2]);
					fflush(stdout);
					system("date");
					printf("\n");
					system(argv[1]);
				}
				else
				{
					switch(argv[1][1])
					{
						case 'n' :
							n=atoi(argv[2]);
							if(n==0)
							{
								printf("watch: failed to parse argument: %s",argv[2]);
								return;
							}
							else
							{
								system("clear");
								printf("every %ds : %s\t\t\t\t\t\t\t\t\t\t\t\t\t",n,argv[3]);
								fflush(stdout);
								system("date");
								printf("\n");
								system(argv[3]);
							} 
							break;                                 

						case 't' :
							system("clear");
							system(argv[2]);
							break;
						case 'g' :
							printf("every %ds : %s\t\t\t\t\t\t\t\t\t\t\t\t\t",n,argv[2]);
							fflush(stdout);
							system("date");
							printf("\n");
							system("\t\tdate");
							system(argv[2]);
							break;
						case 'h' :
							printf("\nusage :  watch [options] command\nOptions:\n-g, --chgexit          exit when output from command changes\n-n, --interval <secs>  seconds to wait between updates\n-t, --no-title         turn off header\n-h, --help     display this help and exit\n");
                                                          break;
						default  :;
					}
					if(argv[1][1]=='g'||argv[1][1]=='h')
					break;                 
				}
			}
			sleep(n);
		}
	}
	while(1);

}



















