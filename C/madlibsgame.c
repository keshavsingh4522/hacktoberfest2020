char color[50];
char pluralNoun[50];
char celebrity[50];

printf("Enter color: ");
fgets(color, 50, stdin);

printf("Enter plural noun: ");
fgets(pluralNoun, 50, stdin);

printf("Enter celebrity: ");
fgets(celebrity, 50, stdin);

printf("Roses are %s \n", color);
printf("%s are blue \n", pluralNoun);
printf("I love %s \n", celebrity);
