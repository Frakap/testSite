
#include <stdio.h>
#include <string.h>
#define MAX_TOOL 100

typedef struct tools{
    int recordNum;
    char toolName[30];
    int quantity;
    double cost;
} Tool;
void initializeFile(void);
void inputToolData(void);
void listTools(void);
void deleteTool(void);
void updateTool(void);

int main(void){

    initializeFile();
    inputToolData();
    //listTools();
    //deleteTool();
    //updateTool();
    //listTools();
    
    return 0;
}
void initializeFile(void){
	Tool blankTool = { 0, "", 0, 0.0};
    FILE* hardwarePtr = fopen("hardware.dat", "wb");
    if(hardwarePtr == NULL){
        printf("Tool file failed to open!");
    } else {
        for(int i = 0; i < MAX_TOOL; ++i){
            fwrite(&blankTool, sizeof(Tool), 1, hardwarePtr);
        }
    }
    fclose(hardwarePtr); 
}
void inputToolData(void){
	Tool blankTool = { 0, "", 0, 0.0};
	FILE* hardwarePtr;
    if((hardwarePtr = fopen("hardware.dat", "wb")) == NULL){
        printf("Tool file failed to open this time!");
    } else {
        printf("%s", "Enter account number: (1-100, 0 for end of data entry)\n? ");
        scanf("%d", &blankTool.recordNum);
        
        while(blankTool.recordNum != 0){
            printf("%s", "Enter tool name: ");
            scanf("%30s", blankTool.toolName);
            
            printf("%s", "Enter tool quantity: ");
            scanf("%d", &blankTool.quantity);
            
            printf("%s", "Enter tool cost: " );
            scanf("%lf", &blankTool.cost);
            
            fseek(hardwarePtr, (blankTool.recordNum-1)*sizeof(Tool), SEEK_SET);
            fwrite(&blankTool, sizeof(Tool), 1, hardwarePtr);
            
            printf("%s", "Enter another Tool Number: (1-100), ) for end of data entry)\n? ");
            scanf("%d", &blankTool.recordNum);
        }
        fclose(hardwarePtr);
    }
    
}
void listTools(void){
    FILE* hardwarePtr;
    Tool blankTool = {0, "", 0, 0.0};
    if((hardwarePtr = fopen("hardware.dat", "rb")) == NULL){
        printf("Tool file failed to open");
    }else{
    	printf("%s\t%s\t%s\t%s\n", "Record Number: ", "Tool Name: ", "Quantity: ", "Tool cost: ");
       	while(!feof(hardwarePtr)){
        	int result = fread(&blankTool, sizeof(Tool), 1, hardwarePtr);
        	if(result != 0 && blankTool.recordNum != 0){
            	printf("%-6d%-19s%-11d$%10.2lf\n", blankTool.recordNum, blankTool.toolName, blankTool.quantity, blankTool.cost);
        		}
			}	
    }
    fclose(hardwarePtr);
}
void updateTool(void){
    FILE* hardwarePtr;
    Tool toolUpdate = {0, "", 0, 0.0};
    if((hardwarePtr = fopen("hardware.dat", "rb")) == NULL){
        puts("Tool file failed to open");
    } else {
        printf("%s", "Enter the record number to update(1-100)\n? ");
        scanf("%d", &toolUpdate.recordNum);
        fseek(hardwarePtr, (toolUpdate.recordNum - 1)*sizeof(Tool), SEEK_SET);
        
        printf("%s", "Enter the new name: ");
        scanf("%s", toolUpdate.toolName);
        
        printf("%s", "Enter the new quantity: ");
        scanf("%d", &toolUpdate.quantity);
        
        printf("%s", "Enter the new cost: ");
        scanf("%lf", &toolUpdate.cost);
        
        fwrite(&toolUpdate, sizeof(Tool), 1, hardwarePtr);
    }
    fclose(hardwarePtr);
}
void deleteTool(void){
    Tool deleteTool = {0, "", 0, 0.0};
    int recordNum;
    FILE* hardwarePtr = fopen("hardware.dat", "wb");
    printf("%s", "Enter record to delete (0-100)|\n? ");
    scanf("%d", &recordNum);
    if(hardwarePtr == NULL){
        printf("Tool file failed to open!");
    } else {
        fseek(hardwarePtr, (recordNum-1)*sizeof(Tool), SEEK_SET);
        fwrite(&deleteTool, sizeof(Tool), 1, hardwarePtr);
    }
    fclose(hardwarePtr);
}