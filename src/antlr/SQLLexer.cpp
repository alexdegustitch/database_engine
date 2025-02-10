
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
      "T__17", "T__18", "T__19", "T__20", "T__21", "ID", "STRING", "NUMBER", 
      "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'SELECT'", "'FROM'", "';'", "'INSERT INTO'", "'VALUES'", "'('", 
      "')'", "'DELETE FROM'", "'UPDATE'", "'SET'", "'='", "'*'", "','", 
      "'WHERE'", "'ORDER BY'", "'ASC'", "'DESC'", "'>'", "'<'", "'>='", 
      "'<='", "'<>'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "ID", "STRING", "NUMBER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,26,184,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,
  	9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,16,1,16,
  	1,16,1,16,1,16,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,20,1,20,1,20,1,21,
  	1,21,1,21,1,22,1,22,5,22,159,8,22,10,22,12,22,162,9,22,1,23,1,23,5,23,
  	166,8,23,10,23,12,23,169,9,23,1,23,1,23,1,24,4,24,174,8,24,11,24,12,24,
  	175,1,25,4,25,179,8,25,11,25,12,25,180,1,25,1,25,1,167,0,26,1,1,3,2,5,
  	3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,
  	16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,1,0,4,
  	3,0,65,90,95,95,97,122,4,0,48,57,65,90,95,95,97,122,1,0,48,57,3,0,9,10,
  	13,13,32,32,187,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,
  	0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,
  	0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,
  	31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,
  	0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,
  	0,1,53,1,0,0,0,3,60,1,0,0,0,5,65,1,0,0,0,7,67,1,0,0,0,9,79,1,0,0,0,11,
  	86,1,0,0,0,13,88,1,0,0,0,15,90,1,0,0,0,17,102,1,0,0,0,19,109,1,0,0,0,
  	21,113,1,0,0,0,23,115,1,0,0,0,25,117,1,0,0,0,27,119,1,0,0,0,29,125,1,
  	0,0,0,31,134,1,0,0,0,33,138,1,0,0,0,35,143,1,0,0,0,37,145,1,0,0,0,39,
  	147,1,0,0,0,41,150,1,0,0,0,43,153,1,0,0,0,45,156,1,0,0,0,47,163,1,0,0,
  	0,49,173,1,0,0,0,51,178,1,0,0,0,53,54,5,83,0,0,54,55,5,69,0,0,55,56,5,
  	76,0,0,56,57,5,69,0,0,57,58,5,67,0,0,58,59,5,84,0,0,59,2,1,0,0,0,60,61,
  	5,70,0,0,61,62,5,82,0,0,62,63,5,79,0,0,63,64,5,77,0,0,64,4,1,0,0,0,65,
  	66,5,59,0,0,66,6,1,0,0,0,67,68,5,73,0,0,68,69,5,78,0,0,69,70,5,83,0,0,
  	70,71,5,69,0,0,71,72,5,82,0,0,72,73,5,84,0,0,73,74,5,32,0,0,74,75,5,73,
  	0,0,75,76,5,78,0,0,76,77,5,84,0,0,77,78,5,79,0,0,78,8,1,0,0,0,79,80,5,
  	86,0,0,80,81,5,65,0,0,81,82,5,76,0,0,82,83,5,85,0,0,83,84,5,69,0,0,84,
  	85,5,83,0,0,85,10,1,0,0,0,86,87,5,40,0,0,87,12,1,0,0,0,88,89,5,41,0,0,
  	89,14,1,0,0,0,90,91,5,68,0,0,91,92,5,69,0,0,92,93,5,76,0,0,93,94,5,69,
  	0,0,94,95,5,84,0,0,95,96,5,69,0,0,96,97,5,32,0,0,97,98,5,70,0,0,98,99,
  	5,82,0,0,99,100,5,79,0,0,100,101,5,77,0,0,101,16,1,0,0,0,102,103,5,85,
  	0,0,103,104,5,80,0,0,104,105,5,68,0,0,105,106,5,65,0,0,106,107,5,84,0,
  	0,107,108,5,69,0,0,108,18,1,0,0,0,109,110,5,83,0,0,110,111,5,69,0,0,111,
  	112,5,84,0,0,112,20,1,0,0,0,113,114,5,61,0,0,114,22,1,0,0,0,115,116,5,
  	42,0,0,116,24,1,0,0,0,117,118,5,44,0,0,118,26,1,0,0,0,119,120,5,87,0,
  	0,120,121,5,72,0,0,121,122,5,69,0,0,122,123,5,82,0,0,123,124,5,69,0,0,
  	124,28,1,0,0,0,125,126,5,79,0,0,126,127,5,82,0,0,127,128,5,68,0,0,128,
  	129,5,69,0,0,129,130,5,82,0,0,130,131,5,32,0,0,131,132,5,66,0,0,132,133,
  	5,89,0,0,133,30,1,0,0,0,134,135,5,65,0,0,135,136,5,83,0,0,136,137,5,67,
  	0,0,137,32,1,0,0,0,138,139,5,68,0,0,139,140,5,69,0,0,140,141,5,83,0,0,
  	141,142,5,67,0,0,142,34,1,0,0,0,143,144,5,62,0,0,144,36,1,0,0,0,145,146,
  	5,60,0,0,146,38,1,0,0,0,147,148,5,62,0,0,148,149,5,61,0,0,149,40,1,0,
  	0,0,150,151,5,60,0,0,151,152,5,61,0,0,152,42,1,0,0,0,153,154,5,60,0,0,
  	154,155,5,62,0,0,155,44,1,0,0,0,156,160,7,0,0,0,157,159,7,1,0,0,158,157,
  	1,0,0,0,159,162,1,0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,46,1,0,0,
  	0,162,160,1,0,0,0,163,167,5,34,0,0,164,166,9,0,0,0,165,164,1,0,0,0,166,
  	169,1,0,0,0,167,168,1,0,0,0,167,165,1,0,0,0,168,170,1,0,0,0,169,167,1,
  	0,0,0,170,171,5,34,0,0,171,48,1,0,0,0,172,174,7,2,0,0,173,172,1,0,0,0,
  	174,175,1,0,0,0,175,173,1,0,0,0,175,176,1,0,0,0,176,50,1,0,0,0,177,179,
  	7,3,0,0,178,177,1,0,0,0,179,180,1,0,0,0,180,178,1,0,0,0,180,181,1,0,0,
  	0,181,182,1,0,0,0,182,183,6,25,0,0,183,52,1,0,0,0,5,0,160,167,175,180,
  	1,6,0,0
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
