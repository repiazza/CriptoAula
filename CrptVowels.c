#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define ADD '+'
#define SUB '-'
#define CRYPT_MSG   1
#define DECRYPT_MSG 2
#define NO_RULE      FALSE
#define CRYPT_RULE   ADD
#define DECRYPT_RULE SUB
#define CRYPT_AMOUNT 1

#define NOT_ASCII_VOWEL 0
// #define CAPITAL_VOWEL 1
// #define LOWER_VOWEL 2

#define CAPITAL_LOWER_DIFF 32

//                        0  1   2   3   4

int gaiCapitalVowels[8]={65, 69, 73, 79, 85, -1};

int *iAsciiVowel(int iLookUpVw){
  int *iVowel;
  
  for ( iVowel = &gaiCapitalVowels[0]; *iVowel != -1; iVowel ++ ){
       if ( iLookUpVw == *iVowel ||
           iLookUpVw == (*iVowel)+CAPITAL_LOWER_DIFF )
        return iVowel;
  }

  return NOT_ASCII_VOWEL;
}
int iCryptMsg(char *pszInputMsg, int iMsgLen, int iCryptRule){
  char *pCh;
  int *iFoundVowel;

  if ( iMsgLen < 1 )
      return -2;

  for ( pCh = pszInputMsg; *pCh; pCh++ ){
    int iAddr = 0;

    if ( (iFoundVowel = iAsciiVowel(*pCh)) == NOT_ASCII_VOWEL )
      continue;

    if ( *iFoundVowel != *pCh)
      iAddr = CAPITAL_LOWER_DIFF;

    if ( *(iFoundVowel+1) == -1 && iCryptRule == ADD ){
      *pCh = gaiCapitalVowels[0];
    }
    else if ( *iFoundVowel == 'a' && iCryptRule == SUB ) {
      *pCh = gaiCapitalVowels[4];
    }
    else {
      if ( iCryptRule == ADD )
        *pCh = *(iFoundVowel + 1);
      else 
        *pCh = *(iFoundVowel - 1);
    }

    *pCh =  (*pCh) + iAddr;
  }

  return 0;
}

int iDoWorkOnMsg(char *pszInputMsg, int iMsgLen, int iWhat2Do){
  int iRule;
  switch (iWhat2Do)
  {
    case CRYPT_MSG:
      iRule = CRYPT_RULE;   
      break;    
    case DECRYPT_MSG:
      iRule = DECRYPT_RULE;
      break;
    default:
      iRule = NO_RULE;
      break;
  }

  if ( iRule == NO_RULE)
    return -1;

  return iCryptMsg(pszInputMsg, iMsgLen, iRule);
}

int main(int argc, char *argv[]){
  char szInputMsg[256];
  char szOldMsg[256];
  int iChoice = 0;
  char szChoice[16];

  printf("Digite sua mensagem:\n");

  memset(szInputMsg,0,sizeof(szInputMsg));
  memset(szOldMsg,0,sizeof(szOldMsg));

  fgets(szInputMsg, sizeof(szInputMsg), stdin);
  strtok(szInputMsg, "\n");

  strcpy(szOldMsg, szInputMsg);
  
  system("clear");
  do { 
    if( iChoice ){
      system("clear");
      printf("Opção invalida\n");
    }
     printf(
  "Digite o que deseja fazer:\n"
  " 1 - Encriptar\n"
  " 2 - Decriptografar\n"
  " 0 - Sair\n"
     );
    
    memset(szChoice,0,sizeof(szChoice));
    fgets(szChoice, sizeof(szChoice), stdin);
    strtok(szChoice, "\n");

    iChoice = atoi(szChoice);

  } while ( iChoice < 0 || iChoice > 2 );

  if ( iChoice == FALSE )
    return 0;

  iDoWorkOnMsg(szInputMsg, strlen(szInputMsg), iChoice);

  printf(
"Mensagem de entrada:[%s]\n"
"Mensagem de saida:[%s]\n",
  szOldMsg,
  szInputMsg
);

  return 0;

}