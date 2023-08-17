void good_echo(void){
    char p[SIZE];
    fgets(p,SIZE,stdin);
    if(p!=NULL)
        printf("%s",p);
    return;
}