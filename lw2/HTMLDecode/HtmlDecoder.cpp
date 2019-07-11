#include "pch.h"
#include "HtmlDecoder.h"

using namespace std;

const string wanted[] = { "&quot;", "&apos;", "&lt;", "&gt;", "&amp;" };
map<string, string> replacement{
	{ "&quot;", "\"" }, { "&apos;", "'" }, { "&lt;", "<" }, { "&gt;", ">" }, { "&amp;", "&" }
};

void replaceHtmlEntity(string& html, const string& htmlEntity)
{
	size_t pos;

	while ((pos = html.find(htmlEntity, 0)) != string::npos)
	{
		html.replace(pos, htmlEntity.length(), replacement[htmlEntity]);
	}
}

void HtmlDecode(string& html)
{
	for (string htmlEntity : wanted)
	{
		replaceHtmlEntity(html, htmlEntity);
	}
}

/*For tests*/
string GetReplaceHtmlEntity(string& html, const string& htmlEntity)
{
	string newStr = html;
	replaceHtmlEntity(newStr, htmlEntity);
	return newStr;
}

/*For tests*/
string GetHtmlDecode(string& html)
{
	string newStr = html;
	HtmlDecode(newStr);
	return newStr;
}
