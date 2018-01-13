#include "Everything.h"
#include "myHeader.h"
#include <iostream>

int main(int argc, char* argv[]) {
    BOOL flags[2], ok = TRUE;
	TCHAR keyName[MAX_PATH+1];
	DWORD i, keyIndex;
	HKEY hKey, hNextKey;
    //predefined key 
    char* PreDefKeyNames[] = {
		"HKEY_LOCAL_MACHINE",
		"HKEY_CLASSES_ROOT",
		"HKEY_CURRENT_USER",
		"HKEY_CURRENT_CONFIG",
		 NULL};
	HKEY PreDefKeys[] = {
		HKEY_LOCAL_MACHINE,
		HKEY_CLASSES_ROOT,
		HKEY_CURRENT_USER,
		HKEY_CURRENT_CONFIG };
	hKey = PreDefKeys[3];
    char pScan[]="Software";
	if (RegOpenKeyEx(hKey, pScan, 0, KEY_READ, &hNextKey) != ERROR_SUCCESS)
		printf("Cannot open subkey properly\n");
	hKey = hNextKey;
    ok = TraverseRegistry(hKey, PreDefKeyNames[3], NULL, flags);
	RegCloseKey(hKey);
    return 0;
}


