constexpr int g_x { 2 }; // internal linkage only accessible withing a.cpp

// function is declared as static, and can now be used only within this file
// attemps to access it from another file via forward declr will fail(linkage err)
static int add(int x, int y)
{
	return x + y;
}
