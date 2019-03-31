#include "Module.h"
//取运行目录(UNICODE编码)
void GetExePathW(WCHAR*dirbuf, int len) {
	GetModuleFileName(NULL, dirbuf, len);
	(wcsrchr(dirbuf, '\\'))[1] = 0;
}
//取运行目录(ANSII编码);
void GetExePathA(char*dirbuf, int len) {
	GetModuleFileNameA(NULL, dirbuf, len);
	(strrchr(dirbuf, '\\'))[1] = 0;
}
//创建多级目录;
void CreateDirectoryEcA(const char *Dir) {
	char NewDir[256] = { 0 };
	CopyMemory(NewDir, Dir, strlen(Dir) * sizeof(char));
	(strrchr(NewDir, '\\'))[1] = 0;
	SHCreateDirectoryExA(nullptr, (LPCSTR)NewDir, nullptr);
}
//创建多级目录;
void CreateDirectoryEcW(const WCHAR *Dir) {
	WCHAR NewDir[256] = { 0 };
	CopyMemory(NewDir, Dir, wcslen(Dir) * sizeof(WCHAR));
	(wcsrchr(NewDir, '\\'))[1] = 0;
	SHCreateDirectoryExW(nullptr, NewDir, nullptr);
}