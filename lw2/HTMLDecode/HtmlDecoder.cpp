#include "HtmlDecoder.h"
#include "pch.h"

const string wanted[] = { "&quot;", "&apos;", "&lt;", "&gt;", "&amp;" };
map<string, string> replacement{
	{ "&quot;", "\"" }, { "&apos;", "\'" }, { "&lt;", "<" }, { "&gt;", ">" }, { "&amp;", "&" }
};

void replaceHtmlEntity(string& html, const string& htmlEntity)
{
	for (string::iterator position = html.begin(); position != html.end() - htmlEntity.length(); ++position)
	{
		html.replace(*position, htmlEntity.length(), replacement[htmlEntity]);
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
