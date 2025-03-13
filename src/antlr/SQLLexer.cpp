
// Generated from SQL.g4 by ANTLR 4.13.2


#include "SQLLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct SQLLexerStaticData final {
  SQLLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SQLLexerStaticData(const SQLLexerStaticData&) = delete;
  SQLLexerStaticData(SQLLexerStaticData&&) = delete;
  SQLLexerStaticData& operator=(const SQLLexerStaticData&) = delete;
  SQLLexerStaticData& operator=(SQLLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sqllexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SQLLexerStaticData> sqllexerLexerStaticData = nullptr;

void sqllexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (sqllexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(sqllexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SQLLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "T__15", "T__16", 
      "T__17", "T__18", "T__19", "T__20", "T__21", "T__22", "T__23", "T__24", 
      "TYPE", "ID", "STRING", "NUMBER", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'CREATE TABLE'", "'('", "')'", "';'", "'SELECT'", "'FROM'", "'INSERT INTO'", 
      "'VALUES'", "'DELETE FROM'", "'UPDATE'", "'SET'", "'='", "'CREATE INDEX'", 
      "'ON'", "','", "'*'", "'WHERE'", "'ORDER BY'", "'ASC'", "'DESC'", 
      "'>'", "'<'", "'>='", "'<='", "'<>'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "TYPE", "ID", "STRING", "NUMBER", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,30,232,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
  	1,1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,15,1,
  	15,1,16,1,16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,18,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,21,1,
  	21,1,22,1,22,1,22,1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,25,1,
  	25,1,25,1,25,1,25,1,25,3,25,203,8,25,1,26,1,26,5,26,207,8,26,10,26,12,
  	26,210,9,26,1,27,1,27,5,27,214,8,27,10,27,12,27,217,9,27,1,27,1,27,1,
  	28,4,28,222,8,28,11,28,12,28,223,1,29,4,29,227,8,29,11,29,12,29,228,1,
  	29,1,29,1,215,0,30,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,
  	23,12,25,13,27,14,29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,
  	23,47,24,49,25,51,26,53,27,55,28,57,29,59,30,1,0,4,3,0,65,90,95,95,97,
  	122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,3,0,9,10,13,13,32,32,236,0,
  	1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,
  	0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,
  	23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,
  	0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,
  	0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,
  	55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,1,61,1,0,0,0,3,74,1,0,0,0,5,76,1,
  	0,0,0,7,78,1,0,0,0,9,80,1,0,0,0,11,87,1,0,0,0,13,92,1,0,0,0,15,104,1,
  	0,0,0,17,111,1,0,0,0,19,123,1,0,0,0,21,130,1,0,0,0,23,134,1,0,0,0,25,
  	136,1,0,0,0,27,149,1,0,0,0,29,152,1,0,0,0,31,154,1,0,0,0,33,156,1,0,0,
  	0,35,162,1,0,0,0,37,171,1,0,0,0,39,175,1,0,0,0,41,180,1,0,0,0,43,182,
  	1,0,0,0,45,184,1,0,0,0,47,187,1,0,0,0,49,190,1,0,0,0,51,202,1,0,0,0,53,
  	204,1,0,0,0,55,211,1,0,0,0,57,221,1,0,0,0,59,226,1,0,0,0,61,62,5,67,0,
  	0,62,63,5,82,0,0,63,64,5,69,0,0,64,65,5,65,0,0,65,66,5,84,0,0,66,67,5,
  	69,0,0,67,68,5,32,0,0,68,69,5,84,0,0,69,70,5,65,0,0,70,71,5,66,0,0,71,
  	72,5,76,0,0,72,73,5,69,0,0,73,2,1,0,0,0,74,75,5,40,0,0,75,4,1,0,0,0,76,
  	77,5,41,0,0,77,6,1,0,0,0,78,79,5,59,0,0,79,8,1,0,0,0,80,81,5,83,0,0,81,
  	82,5,69,0,0,82,83,5,76,0,0,83,84,5,69,0,0,84,85,5,67,0,0,85,86,5,84,0,
  	0,86,10,1,0,0,0,87,88,5,70,0,0,88,89,5,82,0,0,89,90,5,79,0,0,90,91,5,
  	77,0,0,91,12,1,0,0,0,92,93,5,73,0,0,93,94,5,78,0,0,94,95,5,83,0,0,95,
  	96,5,69,0,0,96,97,5,82,0,0,97,98,5,84,0,0,98,99,5,32,0,0,99,100,5,73,
  	0,0,100,101,5,78,0,0,101,102,5,84,0,0,102,103,5,79,0,0,103,14,1,0,0,0,
  	104,105,5,86,0,0,105,106,5,65,0,0,106,107,5,76,0,0,107,108,5,85,0,0,108,
  	109,5,69,0,0,109,110,5,83,0,0,110,16,1,0,0,0,111,112,5,68,0,0,112,113,
  	5,69,0,0,113,114,5,76,0,0,114,115,5,69,0,0,115,116,5,84,0,0,116,117,5,
  	69,0,0,117,118,5,32,0,0,118,119,5,70,0,0,119,120,5,82,0,0,120,121,5,79,
  	0,0,121,122,5,77,0,0,122,18,1,0,0,0,123,124,5,85,0,0,124,125,5,80,0,0,
  	125,126,5,68,0,0,126,127,5,65,0,0,127,128,5,84,0,0,128,129,5,69,0,0,129,
  	20,1,0,0,0,130,131,5,83,0,0,131,132,5,69,0,0,132,133,5,84,0,0,133,22,
  	1,0,0,0,134,135,5,61,0,0,135,24,1,0,0,0,136,137,5,67,0,0,137,138,5,82,
  	0,0,138,139,5,69,0,0,139,140,5,65,0,0,140,141,5,84,0,0,141,142,5,69,0,
  	0,142,143,5,32,0,0,143,144,5,73,0,0,144,145,5,78,0,0,145,146,5,68,0,0,
  	146,147,5,69,0,0,147,148,5,88,0,0,148,26,1,0,0,0,149,150,5,79,0,0,150,
  	151,5,78,0,0,151,28,1,0,0,0,152,153,5,44,0,0,153,30,1,0,0,0,154,155,5,
  	42,0,0,155,32,1,0,0,0,156,157,5,87,0,0,157,158,5,72,0,0,158,159,5,69,
  	0,0,159,160,5,82,0,0,160,161,5,69,0,0,161,34,1,0,0,0,162,163,5,79,0,0,
  	163,164,5,82,0,0,164,165,5,68,0,0,165,166,5,69,0,0,166,167,5,82,0,0,167,
  	168,5,32,0,0,168,169,5,66,0,0,169,170,5,89,0,0,170,36,1,0,0,0,171,172,
  	5,65,0,0,172,173,5,83,0,0,173,174,5,67,0,0,174,38,1,0,0,0,175,176,5,68,
  	0,0,176,177,5,69,0,0,177,178,5,83,0,0,178,179,5,67,0,0,179,40,1,0,0,0,
  	180,181,5,62,0,0,181,42,1,0,0,0,182,183,5,60,0,0,183,44,1,0,0,0,184,185,
  	5,62,0,0,185,186,5,61,0,0,186,46,1,0,0,0,187,188,5,60,0,0,188,189,5,61,
  	0,0,189,48,1,0,0,0,190,191,5,60,0,0,191,192,5,62,0,0,192,50,1,0,0,0,193,
  	194,5,73,0,0,194,195,5,78,0,0,195,203,5,84,0,0,196,197,5,83,0,0,197,198,
  	5,84,0,0,198,199,5,82,0,0,199,200,5,73,0,0,200,201,5,78,0,0,201,203,5,
  	71,0,0,202,193,1,0,0,0,202,196,1,0,0,0,203,52,1,0,0,0,204,208,7,0,0,0,
  	205,207,7,1,0,0,206,205,1,0,0,0,207,210,1,0,0,0,208,206,1,0,0,0,208,209,
  	1,0,0,0,209,54,1,0,0,0,210,208,1,0,0,0,211,215,5,34,0,0,212,214,9,0,0,
  	0,213,212,1,0,0,0,214,217,1,0,0,0,215,216,1,0,0,0,215,213,1,0,0,0,216,
  	218,1,0,0,0,217,215,1,0,0,0,218,219,5,34,0,0,219,56,1,0,0,0,220,222,7,
  	2,0,0,221,220,1,0,0,0,222,223,1,0,0,0,223,221,1,0,0,0,223,224,1,0,0,0,
  	224,58,1,0,0,0,225,227,7,3,0,0,226,225,1,0,0,0,227,228,1,0,0,0,228,226,
  	1,0,0,0,228,229,1,0,0,0,229,230,1,0,0,0,230,231,6,29,0,0,231,60,1,0,0,
  	0,6,0,202,208,215,223,228,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sqllexerLexerStaticData = std::move(staticData);
}

}

SQLLexer::SQLLexer(CharStream *input) : Lexer(input) {
  SQLLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *sqllexerLexerStaticData->atn, sqllexerLexerStaticData->decisionToDFA, sqllexerLexerStaticData->sharedContextCache);
}

SQLLexer::~SQLLexer() {
  delete _interpreter;
}

std::string SQLLexer::getGrammarFileName() const {
  return "SQL.g4";
}

const std::vector<std::string>& SQLLexer::getRuleNames() const {
  return sqllexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& SQLLexer::getChannelNames() const {
  return sqllexerLexerStaticData->channelNames;
}

const std::vector<std::string>& SQLLexer::getModeNames() const {
  return sqllexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& SQLLexer::getVocabulary() const {
  return sqllexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SQLLexer::getSerializedATN() const {
  return sqllexerLexerStaticData->serializedATN;
}

const atn::ATN& SQLLexer::getATN() const {
  return *sqllexerLexerStaticData->atn;
}




void SQLLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  sqllexerLexerInitialize();
#else
  ::antlr4::internal::call_once(sqllexerLexerOnceFlag, sqllexerLexerInitialize);
#endif
}
