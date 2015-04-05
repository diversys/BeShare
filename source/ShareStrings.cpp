#include "ShareStrings.h"

#include "support/MuscleSupport.h"
#include "util/String.h"

#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "ShareStrings"

using namespace muscle;

namespace beshare {
	
# define ARRAYITEMS(x) (sizeof(x)/sizeof(x[0]))  /* returns # of items in array */

static int _language = LANGUAGE_ENGLISH;	// Everybody's favorite language!

void PrintLanguage()
{
	printf("Starting\n");
	for ( int fooInt = LANGUAGE_ENGLISH; fooInt != LANGUAGE_FINNISH; fooInt++ ) {
		LANGUAGE lan = static_cast<LANGUAGE>(fooInt);
		printf("------------------------\n");
		printf("%s\n", GetLanguageName(lan, false));
		printf("------------------------\n");
//		for ( int fooInt = STR_ANONYMOUS; fooInt != STR_UPTIME; fooInt++ ) {
//			LANSTRING lanstr = static_cast<LANSTRING>(fooInt);
//			printf("%s\n", str(lanstr, lan));
//		}
	}

}

// Returns the best LANGUAGE_* value based on our environment variables, or LANGUAGE_ENGLISH 
// if nothing can be deduced.  Contributed by Francois Revol (revol@free.fr)
int GetDefaultLanguageForLocale()
{
	static const struct 
	{
		const char *posix; 
		int language; 
	} 
	posixLocaleMapping[] = 
	{ 
		{"C",  LANGUAGE_ENGLISH}, // the default one 
		{"en", LANGUAGE_ENGLISH}, 
		{"es", LANGUAGE_SPANISH}, 
		{"de", LANGUAGE_GERMAN}, 
		{"nl", LANGUAGE_DUTCH}, 
		{"pt", LANGUAGE_PORTUGUESE}, 
		{"fr", LANGUAGE_FRENCH}, 
		{"it", LANGUAGE_ITALIAN}, 
		{"ru", LANGUAGE_RUSSIAN}, 
		{"sv", LANGUAGE_SWEDISH}, 
		{"eo", LANGUAGE_ESPERANTO}, 
		{"no", LANGUAGE_NORWEGIAN}, 
		{"sr", LANGUAGE_SERBIAN}, 
		{"bg", LANGUAGE_BULGARIAN}, 
		{"ko", LANGUAGE_KOREAN}, 
		{"hu", LANGUAGE_HUNGARIAN}, 
		{"ro", LANGUAGE_ROMANIAN}, 
		{"zh", LANGUAGE_SCHINESE},  // simplified Chinese 
		{"tk", LANGUAGE_TURKISH},
		{"ja", LANGUAGE_JAPANESE},
		{"fi", LANGUAGE_FINNISH}
	}; 

	String posixLocale(getenv("LC_ALL")); 
	if (posixLocale.Length() == 0)
		posixLocale = getenv("LC_MESSAGES"); 
	
	if (posixLocale.Length() > 0) {
		posixLocale = posixLocale.Substring(0, "_");  // remove everything at/after 1st underbar
		for (uint32 i = 0; i < ARRAYITEMS(posixLocaleMapping); i++)
			if (posixLocale == posixLocaleMapping[i].posix)
				return posixLocaleMapping[i].language; 
	}
	return LANGUAGE_ENGLISH;  // the default
}

static const char _englishShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _englishStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _spanishShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'E',  // "Bye" to current connection
	'P',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'I',  // Open private chat window
	'F',  // Toggle file logging
	'S',  // File sharing enabled
	'O',  // Logs dir
};

// Submitted by: Phantom (socca@bemail.org) and Pintaio (pinpedilicio@yahoo.es)
static const char * _spanishStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _germanShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'T',  // "Bye" to current connection
	'F',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'Z',  // Reset Layout
	'Q',  // Quit
	'K',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'G',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _germanStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _dutchShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'G',  // Shared dir
	'I',  // Download dir
	'L',  // clear Log
	'H',  // Reset Layout
	'Q',  // Quit
	'Z',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _dutchStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _portugueseShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _portugueseStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _frenchShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'P',  // Shared dir
	'T',  // Download dir
	'E',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'I',  // Open private chat window
	'F',  // Toggle file logging
	'S',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _frenchStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _italianShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'I',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _italianStrings[NUM_STRINGS] = {

	"Display uptime"
};

static const char _russianShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'I',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _russianStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _esperantoShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _esperantoStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _swedishShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'K',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'A',  // Quit
	'U',  // Full user Queries
	'O',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'G',  // Logs dir
};

static const char * _swedishStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _norwegianShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _norwegianStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _serbianShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _serbianStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _bulgarianShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _bulgarianStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _koreanShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _koreanStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _hungarianShortcuts[NUM_SHORTCUTS] = {
	'N', // New connection
	'B', // "Bye" to current connection
	'S', // Shared dir
	'D', // Download dir
	'L', // clear Log
	'R', // Reset Layout
	'Q', // Quit
	'U', // Full user Queries
	'M', // Beep When Mentioned
	'P', // Open private chat window
	'F', // Toggle file logging
	'E', // File sharing enabled
	'O', // Logs dir
};

static const char * _hungarianStrings[NUM_STRINGS] = {
	"Display uptime"
};


static const char _romanianShortcuts[NUM_SHORTCUTS] = {
	'N', // New connection
	'B', // "Bye" to current connection
	'S', // Shared dir
	'D', // Download dir
	'L', // clear Log
	'R', // Reset Layout
	'Q', // Quit
	'U', // Full user Queries
	'M', // Beep When Mentioned
	'P', // Open private chat window
	'F', // Toggle file logging
	'E', // File sharing enabled
	'O', // Logs dir
};

static const char * _romanianStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _schineseShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection				  - 新连接
	'B',  // "Bye" to current connection - 断开当前连接
	'S',  // Shared dir						- 共享目录
	'D',  // Download dir					 - 下载目录
	'L',  // clear Log						 - 清空日志
	'R',  // Reset Layout					 - 重置布局
	'Q',  // Quit								- 退出
	'U',  // Full user Queries			  - 完全匹配用户查询条件
	'M',  // Beep When Mentioned			- 被呼唤时提示
	'P',  // Open private chat window	 - 打开密聊窗口
	'F',  // Toggle file logging			- 锁定文件日志
	'E',  // File sharing enabled		  - 启用文件共享
	'O',  // Logs dir						  - 日志目录
};

static const char * _schineseStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _turkishShortcuts[NUM_SHORTCUTS] = {
	'N',  // Yeni Bağlantı
	'B',  // Yürütülen Bağlantıyı bitir
	'S',  // Paylaşılan Klasör
	'D',  // Dosya indirme Klasörü
	'L',  // Oturum Notlarını sil
	'R',  // Uygulama görünümü standard değerle getir
	'Q',  // Bitir
	'U',  // Komple kullanıcı sorgulamaları
	'M',  // Konu olunduğunda sinyal çal
	'P',  // Özel görüşme penceresini aç
	'F',  // Oturum notlarını değiştir
	'E',  // Dosya paylaşmaya izin ver
	'O',  // Oturum Notların Klasörü
};

static const char * _turkishStrings[NUM_STRINGS] = {
	"Display uptime"
};


static const char _japaneseShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _japaneseStrings[NUM_STRINGS] = {
	"Display uptime"
};

static const char _finnishShortcuts[NUM_SHORTCUTS] = {
	'N',  // New connection
	'B',  // "Bye" to current connection
	'S',  // Shared dir
	'D',  // Download dir
	'L',  // clear Log
	'R',  // Reset Layout
	'Q',  // Quit
	'U',  // Full user Queries
	'M',  // Beep When Mentioned
	'P',  // Open private chat window
	'F',  // Toggle file logging
	'E',  // File sharing enabled
	'O',  // Logs dir
};

static const char * _finnishStrings[NUM_STRINGS] = {
	"Display uptime"
};

int GetLanguage()
{
	return _language;
}

void SetLanguage(int wl)
{
	if ((wl >= 0)&&(wl < NUM_LANGUAGES)) _language = wl;
}

const char * GetLanguageName(int wl, bool native)
{
#if 0
	switch(wl)
	{
		case LANGUAGE_ENGLISH:	 return B_TRANSLATE(STR_ENGLISH),	 native ? LANGUAGE_ENGLISH	 : _language);
		case LANGUAGE_SPANISH:	 return B_TRANSLATE(STR_SPANISH),	 native ? LANGUAGE_SPANISH	 : _language);
		case LANGUAGE_GERMAN:	  return B_TRANSLATE(STR_GERMAN),	  native ? LANGUAGE_GERMAN	  : _language);
		case LANGUAGE_DUTCH:		return B_TRANSLATE(STR_DUTCH),		native ? LANGUAGE_DUTCH		: _language);
		case LANGUAGE_PORTUGUESE: return B_TRANSLATE(STR_PORTUGUESE), native ? LANGUAGE_PORTUGUESE : _language);
		case LANGUAGE_FRENCH:	  return B_TRANSLATE(STR_FRENCH),	  native ? LANGUAGE_FRENCH	  : _language);
		case LANGUAGE_ITALIAN:	 return B_TRANSLATE(STR_ITALIAN),	 native ? LANGUAGE_ITALIAN	 : _language);
		case LANGUAGE_RUSSIAN:	 return B_TRANSLATE(STR_RUSSIAN),	 native ? LANGUAGE_RUSSIAN	 : _language);
		case LANGUAGE_SWEDISH:	 return B_TRANSLATE(STR_SWEDISH),	 native ? LANGUAGE_SWEDISH	 : _language);
		case LANGUAGE_ESPERANTO:  return B_TRANSLATE(STR_ESPERANTO),  native ? LANGUAGE_ESPERANTO  : _language);
		case LANGUAGE_NORWEGIAN:  return B_TRANSLATE(STR_NORWEGIAN),  native ? LANGUAGE_NORWEGIAN  : _language);
		case LANGUAGE_SERBIAN:	 return B_TRANSLATE(STR_SERBIAN),	 native ? LANGUAGE_SERBIAN	 : _language);
		case LANGUAGE_BULGARIAN:  return B_TRANSLATE(STR_BULGARIAN),  native ? LANGUAGE_BULGARIAN  : _language);
		case LANGUAGE_KOREAN:	  return B_TRANSLATE(STR_KOREAN),	  native ? LANGUAGE_KOREAN	  : _language);
		case LANGUAGE_HUNGARIAN:  return B_TRANSLATE(STR_HUNGARIAN),  native ? LANGUAGE_HUNGARIAN  : _language);
		case LANGUAGE_ROMANIAN:	return B_TRANSLATE(STR_ROMANIAN),	native ? LANGUAGE_ROMANIAN	: _language);
		case LANGUAGE_SCHINESE:	return B_TRANSLATE(STR_SCHINESE),	native ? LANGUAGE_SCHINESE	: _language);
		case LANGUAGE_TURKISH:	 return B_TRANSLATE(STR_TURKISH),	 native ? LANGUAGE_TURKISH	 : _language);
		case LANGUAGE_JAPANESE:	return B_TRANSLATE(STR_JAPANESE),	native ? LANGUAGE_JAPANESE	: _language);
		case LANGUAGE_FINNISH:	 return B_TRANSLATE(STR_FINNISH),	 native ? LANGUAGE_FINNISH	 : _language);
		case LANGUAGE_MALKOVITCH: return "Malkovich";
		default:						MASSERT(false, "Bad language token!"); return 0;
	}
#endif
}

const char * str(int ws, int language)
{
	const char ** base = NULL;
	switch((language < 0) ? _language : language)
	{
		case LANGUAGE_ENGLISH:	 base = _englishStrings;	 break;
		case LANGUAGE_SPANISH:	 base = _spanishStrings;	 break;
		case LANGUAGE_GERMAN:	  base = _germanStrings;	  break;
		case LANGUAGE_DUTCH:		base = _dutchStrings;		break;
		case LANGUAGE_PORTUGUESE: base = _portugueseStrings; break;
		case LANGUAGE_FRENCH:	  base = _frenchStrings;	  break;
		case LANGUAGE_ITALIAN:	 base = _italianStrings;	 break;
		case LANGUAGE_RUSSIAN:	 base = _russianStrings;	 break;
		case LANGUAGE_SWEDISH:	 base = _swedishStrings;	 break;
		case LANGUAGE_ESPERANTO:  base = _esperantoStrings;  break;
		case LANGUAGE_NORWEGIAN:  base = _norwegianStrings;  break;
		case LANGUAGE_SERBIAN:	 base = _serbianStrings;	 break;
		case LANGUAGE_BULGARIAN:  base = _bulgarianStrings;  break;
		case LANGUAGE_KOREAN:	  base = _koreanStrings;	  break;
		case LANGUAGE_HUNGARIAN:  base = _hungarianStrings;  break;
		case LANGUAGE_ROMANIAN:	base = _romanianStrings;	break;
		case LANGUAGE_SCHINESE:	base = _schineseStrings;	break;
		case LANGUAGE_TURKISH:	 base = _turkishStrings;	 break;
		case LANGUAGE_JAPANESE:	base = _japaneseStrings;	break;
		case LANGUAGE_FINNISH:	 base = _finnishStrings;	 break;
		case LANGUAGE_MALKOVITCH:
#if 0
		{
			switch(ws)
			{ 
				case STR_FILE_NAME_KEY:  return "Malkovich";  // gotta make sure these are
				case STR_USER_KEY:		 return "Malkovich";  // prefixed correctly, even
				case STR_SESSIONID_KEY:  return "Malkovich";  // inside Malkovich-land
				case STR_CONNECTION_KEY: return "Malkovich";
				default:					  return "Malkovich";
			}
		}
#endif			
		break;
	}

	return ((base)&&(ws >= 0)&&(ws < NUM_STRINGS)) ? base[ws] : NULL;
}

char shortcut(int sc)
{
	const char * base = NULL;
	switch(_language)
	{
		case LANGUAGE_ENGLISH:	 base = _englishShortcuts; break;
		case LANGUAGE_SPANISH:	 base = _spanishShortcuts; break;
		case LANGUAGE_GERMAN:	  base = _germanShortcuts; break;
		case LANGUAGE_DUTCH:		base = _dutchShortcuts; break;
		case LANGUAGE_PORTUGUESE: base = _portugueseShortcuts; break;
		case LANGUAGE_FRENCH:	  base = _frenchShortcuts; break;
		case LANGUAGE_ITALIAN:	 base = _italianShortcuts; break;
		case LANGUAGE_RUSSIAN:	 base = _russianShortcuts; break;
		case LANGUAGE_SWEDISH:	 base = _swedishShortcuts; break;
		case LANGUAGE_ESPERANTO:  base = _esperantoShortcuts; break;
		case LANGUAGE_NORWEGIAN:  base = _norwegianShortcuts; break;
		case LANGUAGE_SERBIAN:	 base = _serbianShortcuts; break;
		case LANGUAGE_BULGARIAN:  base = _bulgarianShortcuts; break;
		case LANGUAGE_KOREAN:	  base = _koreanShortcuts; break;
		case LANGUAGE_HUNGARIAN:  base = _hungarianShortcuts; break;
		case LANGUAGE_ROMANIAN:	base = _romanianShortcuts; break;
		case LANGUAGE_SCHINESE:	base = _schineseShortcuts; break;
		case LANGUAGE_TURKISH:	 base = _turkishShortcuts; break;
		case LANGUAGE_JAPANESE:	base = _japaneseShortcuts; break;
		case LANGUAGE_FINNISH:	 base = _finnishShortcuts; break;
		case LANGUAGE_MALKOVITCH: return 'M';
	}
	return ((base)&&(sc >= 0)&&(sc < NUM_SHORTCUTS)) ? base[sc] : 0;
}

}
;  // end namespace beshare
