
// Generated from SQL.g4 by ANTLR 4.13.2


#include "SQLListener.h"
#include "SQLVisitor.h"

#include "SQLParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct SQLParserStaticData final {
  SQLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SQLParserStaticData(const SQLParserStaticData&) = delete;
  SQLParserStaticData(SQLParserStaticData&&) = delete;
  SQLParserStaticData& operator=(const SQLParserStaticData&) = delete;
  SQLParserStaticData& operator=(SQLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag sqlParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<SQLParserStaticData> sqlParserStaticData = nullptr;

void sqlParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (sqlParserStaticData != nullptr) {
    return;
  }
#else
  assert(sqlParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<SQLParserStaticData>(
    std::vector<std::string>{
      "query", "createQuery", "selectQuery", "insertQuery", "deleteQuery", 
      "updateQuery", "createIndex", "insertColumns", "columns", "column", 
      "tableName", "indexName", "whereClause", "orderByClause", "condition", 
      "orCondition", "andCondition", "baseCondition", "columnValueCondition", 
      "operator", "tableValues", "tableValue", "values", "value"
    },
    std::vector<std::string>{
      "", "'CREATE TABLE'", "'('", "')'", "';'", "'SELECT'", "'FROM'", "'INSERT INTO'", 
      "'VALUES'", "'DELETE FROM'", "'UPDATE'", "'SET'", "'='", "'CREATE INDEX'", 
      "'ON'", "','", "'*'", "'WHERE'", "'ORDER BY'", "'ASC'", "'DESC'", 
      "'>'", "'<'", "'>='", "'<='", "'<>'", "'AND'", "'OR'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "", "", "", "", "", "", "", "", "", "AND", "OR", "TYPE", "VARCHAR", 
      "ID", "STRING", "NUMBER", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,33,202,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,0,1,0,1,0,3,0,55,8,0,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,3,2,69,8,2,1,2,3,2,72,8,2,1,2,1,2,
  	1,3,1,3,1,3,1,3,1,3,1,3,3,3,82,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,
  	4,3,4,93,8,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,104,8,5,1,5,1,5,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,5,7,120,8,7,10,7,12,7,
  	123,9,7,1,8,1,8,1,8,1,8,5,8,129,8,8,10,8,12,8,132,9,8,3,8,134,8,8,1,9,
  	1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,3,13,148,8,13,1,
  	14,1,14,1,15,1,15,1,15,5,15,155,8,15,10,15,12,15,158,9,15,1,16,1,16,1,
  	16,5,16,163,8,16,10,16,12,16,166,9,16,1,17,1,17,1,17,1,17,1,17,3,17,173,
  	8,17,1,18,1,18,1,18,1,18,1,19,1,19,1,20,1,20,1,20,5,20,184,8,20,10,20,
  	12,20,187,9,20,1,21,1,21,1,21,1,22,1,22,1,22,5,22,195,8,22,10,22,12,22,
  	198,9,22,1,23,1,23,1,23,0,0,24,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,0,3,1,0,19,20,2,0,12,12,21,25,1,0,30,32,196,
  	0,54,1,0,0,0,2,56,1,0,0,0,4,63,1,0,0,0,6,75,1,0,0,0,8,89,1,0,0,0,10,96,
  	1,0,0,0,12,107,1,0,0,0,14,116,1,0,0,0,16,133,1,0,0,0,18,135,1,0,0,0,20,
  	137,1,0,0,0,22,139,1,0,0,0,24,141,1,0,0,0,26,144,1,0,0,0,28,149,1,0,0,
  	0,30,151,1,0,0,0,32,159,1,0,0,0,34,172,1,0,0,0,36,174,1,0,0,0,38,178,
  	1,0,0,0,40,180,1,0,0,0,42,188,1,0,0,0,44,191,1,0,0,0,46,199,1,0,0,0,48,
  	55,3,2,1,0,49,55,3,4,2,0,50,55,3,6,3,0,51,55,3,8,4,0,52,55,3,10,5,0,53,
  	55,3,12,6,0,54,48,1,0,0,0,54,49,1,0,0,0,54,50,1,0,0,0,54,51,1,0,0,0,54,
  	52,1,0,0,0,54,53,1,0,0,0,55,1,1,0,0,0,56,57,5,1,0,0,57,58,3,20,10,0,58,
  	59,5,2,0,0,59,60,3,40,20,0,60,61,5,3,0,0,61,62,5,4,0,0,62,3,1,0,0,0,63,
  	64,5,5,0,0,64,65,3,16,8,0,65,66,5,6,0,0,66,68,3,20,10,0,67,69,3,24,12,
  	0,68,67,1,0,0,0,68,69,1,0,0,0,69,71,1,0,0,0,70,72,3,26,13,0,71,70,1,0,
  	0,0,71,72,1,0,0,0,72,73,1,0,0,0,73,74,5,4,0,0,74,5,1,0,0,0,75,76,5,7,
  	0,0,76,81,3,20,10,0,77,78,5,2,0,0,78,79,3,14,7,0,79,80,5,3,0,0,80,82,
  	1,0,0,0,81,77,1,0,0,0,81,82,1,0,0,0,82,83,1,0,0,0,83,84,5,8,0,0,84,85,
  	5,2,0,0,85,86,3,44,22,0,86,87,5,3,0,0,87,88,5,4,0,0,88,7,1,0,0,0,89,90,
  	5,9,0,0,90,92,3,20,10,0,91,93,3,24,12,0,92,91,1,0,0,0,92,93,1,0,0,0,93,
  	94,1,0,0,0,94,95,5,4,0,0,95,9,1,0,0,0,96,97,5,10,0,0,97,98,3,20,10,0,
  	98,99,5,11,0,0,99,100,3,18,9,0,100,101,5,12,0,0,101,103,3,46,23,0,102,
  	104,3,24,12,0,103,102,1,0,0,0,103,104,1,0,0,0,104,105,1,0,0,0,105,106,
  	5,4,0,0,106,11,1,0,0,0,107,108,5,13,0,0,108,109,3,22,11,0,109,110,5,14,
  	0,0,110,111,3,20,10,0,111,112,5,2,0,0,112,113,3,18,9,0,113,114,5,3,0,
  	0,114,115,5,4,0,0,115,13,1,0,0,0,116,121,3,18,9,0,117,118,5,15,0,0,118,
  	120,3,18,9,0,119,117,1,0,0,0,120,123,1,0,0,0,121,119,1,0,0,0,121,122,
  	1,0,0,0,122,15,1,0,0,0,123,121,1,0,0,0,124,134,5,16,0,0,125,130,3,18,
  	9,0,126,127,5,15,0,0,127,129,3,18,9,0,128,126,1,0,0,0,129,132,1,0,0,0,
  	130,128,1,0,0,0,130,131,1,0,0,0,131,134,1,0,0,0,132,130,1,0,0,0,133,124,
  	1,0,0,0,133,125,1,0,0,0,134,17,1,0,0,0,135,136,5,30,0,0,136,19,1,0,0,
  	0,137,138,5,30,0,0,138,21,1,0,0,0,139,140,5,30,0,0,140,23,1,0,0,0,141,
  	142,5,17,0,0,142,143,3,28,14,0,143,25,1,0,0,0,144,145,5,18,0,0,145,147,
  	3,18,9,0,146,148,7,0,0,0,147,146,1,0,0,0,147,148,1,0,0,0,148,27,1,0,0,
  	0,149,150,3,30,15,0,150,29,1,0,0,0,151,156,3,32,16,0,152,153,5,27,0,0,
  	153,155,3,32,16,0,154,152,1,0,0,0,155,158,1,0,0,0,156,154,1,0,0,0,156,
  	157,1,0,0,0,157,31,1,0,0,0,158,156,1,0,0,0,159,164,3,34,17,0,160,161,
  	5,26,0,0,161,163,3,34,17,0,162,160,1,0,0,0,163,166,1,0,0,0,164,162,1,
  	0,0,0,164,165,1,0,0,0,165,33,1,0,0,0,166,164,1,0,0,0,167,168,5,2,0,0,
  	168,169,3,28,14,0,169,170,5,3,0,0,170,173,1,0,0,0,171,173,3,36,18,0,172,
  	167,1,0,0,0,172,171,1,0,0,0,173,35,1,0,0,0,174,175,3,18,9,0,175,176,3,
  	38,19,0,176,177,3,46,23,0,177,37,1,0,0,0,178,179,7,1,0,0,179,39,1,0,0,
  	0,180,185,3,42,21,0,181,182,5,15,0,0,182,184,3,42,21,0,183,181,1,0,0,
  	0,184,187,1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,41,1,0,0,0,187,
  	185,1,0,0,0,188,189,3,46,23,0,189,190,5,28,0,0,190,43,1,0,0,0,191,196,
  	3,46,23,0,192,193,5,15,0,0,193,195,3,46,23,0,194,192,1,0,0,0,195,198,
  	1,0,0,0,196,194,1,0,0,0,196,197,1,0,0,0,197,45,1,0,0,0,198,196,1,0,0,
  	0,199,200,7,2,0,0,200,47,1,0,0,0,15,54,68,71,81,92,103,121,130,133,147,
  	156,164,172,185,196
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  sqlParserStaticData = std::move(staticData);
}

}

SQLParser::SQLParser(TokenStream *input) : SQLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

SQLParser::SQLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  SQLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *sqlParserStaticData->atn, sqlParserStaticData->decisionToDFA, sqlParserStaticData->sharedContextCache, options);
}

SQLParser::~SQLParser() {
  delete _interpreter;
}

const atn::ATN& SQLParser::getATN() const {
  return *sqlParserStaticData->atn;
}

std::string SQLParser::getGrammarFileName() const {
  return "SQL.g4";
}

const std::vector<std::string>& SQLParser::getRuleNames() const {
  return sqlParserStaticData->ruleNames;
}

const dfa::Vocabulary& SQLParser::getVocabulary() const {
  return sqlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView SQLParser::getSerializedATN() const {
  return sqlParserStaticData->serializedATN;
}


//----------------- QueryContext ------------------------------------------------------------------

SQLParser::QueryContext::QueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::CreateQueryContext* SQLParser::QueryContext::createQuery() {
  return getRuleContext<SQLParser::CreateQueryContext>(0);
}

SQLParser::SelectQueryContext* SQLParser::QueryContext::selectQuery() {
  return getRuleContext<SQLParser::SelectQueryContext>(0);
}

SQLParser::InsertQueryContext* SQLParser::QueryContext::insertQuery() {
  return getRuleContext<SQLParser::InsertQueryContext>(0);
}

SQLParser::DeleteQueryContext* SQLParser::QueryContext::deleteQuery() {
  return getRuleContext<SQLParser::DeleteQueryContext>(0);
}

SQLParser::UpdateQueryContext* SQLParser::QueryContext::updateQuery() {
  return getRuleContext<SQLParser::UpdateQueryContext>(0);
}

SQLParser::CreateIndexContext* SQLParser::QueryContext::createIndex() {
  return getRuleContext<SQLParser::CreateIndexContext>(0);
}


size_t SQLParser::QueryContext::getRuleIndex() const {
  return SQLParser::RuleQuery;
}

void SQLParser::QueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQuery(this);
}

void SQLParser::QueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQuery(this);
}


std::any SQLParser::QueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitQuery(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::QueryContext* SQLParser::query() {
  QueryContext *_localctx = _tracker.createInstance<QueryContext>(_ctx, getState());
  enterRule(_localctx, 0, SQLParser::RuleQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(54);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(48);
        createQuery();
        break;
      }

      case SQLParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(49);
        selectQuery();
        break;
      }

      case SQLParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(50);
        insertQuery();
        break;
      }

      case SQLParser::T__8: {
        enterOuterAlt(_localctx, 4);
        setState(51);
        deleteQuery();
        break;
      }

      case SQLParser::T__9: {
        enterOuterAlt(_localctx, 5);
        setState(52);
        updateQuery();
        break;
      }

      case SQLParser::T__12: {
        enterOuterAlt(_localctx, 6);
        setState(53);
        createIndex();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateQueryContext ------------------------------------------------------------------

SQLParser::CreateQueryContext::CreateQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::TableNameContext* SQLParser::CreateQueryContext::tableName() {
  return getRuleContext<SQLParser::TableNameContext>(0);
}

SQLParser::TableValuesContext* SQLParser::CreateQueryContext::tableValues() {
  return getRuleContext<SQLParser::TableValuesContext>(0);
}


size_t SQLParser::CreateQueryContext::getRuleIndex() const {
  return SQLParser::RuleCreateQuery;
}

void SQLParser::CreateQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateQuery(this);
}

void SQLParser::CreateQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateQuery(this);
}


std::any SQLParser::CreateQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitCreateQuery(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::CreateQueryContext* SQLParser::createQuery() {
  CreateQueryContext *_localctx = _tracker.createInstance<CreateQueryContext>(_ctx, getState());
  enterRule(_localctx, 2, SQLParser::RuleCreateQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(SQLParser::T__0);
    setState(57);
    tableName();
    setState(58);
    match(SQLParser::T__1);
    setState(59);
    tableValues();
    setState(60);
    match(SQLParser::T__2);
    setState(61);
    match(SQLParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectQueryContext ------------------------------------------------------------------

SQLParser::SelectQueryContext::SelectQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::ColumnsContext* SQLParser::SelectQueryContext::columns() {
  return getRuleContext<SQLParser::ColumnsContext>(0);
}

SQLParser::TableNameContext* SQLParser::SelectQueryContext::tableName() {
  return getRuleContext<SQLParser::TableNameContext>(0);
}

SQLParser::WhereClauseContext* SQLParser::SelectQueryContext::whereClause() {
  return getRuleContext<SQLParser::WhereClauseContext>(0);
}

SQLParser::OrderByClauseContext* SQLParser::SelectQueryContext::orderByClause() {
  return getRuleContext<SQLParser::OrderByClauseContext>(0);
}


size_t SQLParser::SelectQueryContext::getRuleIndex() const {
  return SQLParser::RuleSelectQuery;
}

void SQLParser::SelectQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectQuery(this);
}

void SQLParser::SelectQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectQuery(this);
}


std::any SQLParser::SelectQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitSelectQuery(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::SelectQueryContext* SQLParser::selectQuery() {
  SelectQueryContext *_localctx = _tracker.createInstance<SelectQueryContext>(_ctx, getState());
  enterRule(_localctx, 4, SQLParser::RuleSelectQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(SQLParser::T__4);
    setState(64);
    columns();
    setState(65);
    match(SQLParser::T__5);
    setState(66);
    tableName();
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__16) {
      setState(67);
      whereClause();
    }
    setState(71);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__17) {
      setState(70);
      orderByClause();
    }
    setState(73);
    match(SQLParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertQueryContext ------------------------------------------------------------------

SQLParser::InsertQueryContext::InsertQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::TableNameContext* SQLParser::InsertQueryContext::tableName() {
  return getRuleContext<SQLParser::TableNameContext>(0);
}

SQLParser::ValuesContext* SQLParser::InsertQueryContext::values() {
  return getRuleContext<SQLParser::ValuesContext>(0);
}

SQLParser::InsertColumnsContext* SQLParser::InsertQueryContext::insertColumns() {
  return getRuleContext<SQLParser::InsertColumnsContext>(0);
}


size_t SQLParser::InsertQueryContext::getRuleIndex() const {
  return SQLParser::RuleInsertQuery;
}

void SQLParser::InsertQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsertQuery(this);
}

void SQLParser::InsertQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsertQuery(this);
}


std::any SQLParser::InsertQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitInsertQuery(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::InsertQueryContext* SQLParser::insertQuery() {
  InsertQueryContext *_localctx = _tracker.createInstance<InsertQueryContext>(_ctx, getState());
  enterRule(_localctx, 6, SQLParser::RuleInsertQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(SQLParser::T__6);
    setState(76);
    tableName();
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__1) {
      setState(77);
      match(SQLParser::T__1);
      setState(78);
      insertColumns();
      setState(79);
      match(SQLParser::T__2);
    }
    setState(83);
    match(SQLParser::T__7);
    setState(84);
    match(SQLParser::T__1);
    setState(85);
    values();
    setState(86);
    match(SQLParser::T__2);
    setState(87);
    match(SQLParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeleteQueryContext ------------------------------------------------------------------

SQLParser::DeleteQueryContext::DeleteQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::TableNameContext* SQLParser::DeleteQueryContext::tableName() {
  return getRuleContext<SQLParser::TableNameContext>(0);
}

SQLParser::WhereClauseContext* SQLParser::DeleteQueryContext::whereClause() {
  return getRuleContext<SQLParser::WhereClauseContext>(0);
}


size_t SQLParser::DeleteQueryContext::getRuleIndex() const {
  return SQLParser::RuleDeleteQuery;
}

void SQLParser::DeleteQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeleteQuery(this);
}

void SQLParser::DeleteQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeleteQuery(this);
}


std::any SQLParser::DeleteQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitDeleteQuery(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::DeleteQueryContext* SQLParser::deleteQuery() {
  DeleteQueryContext *_localctx = _tracker.createInstance<DeleteQueryContext>(_ctx, getState());
  enterRule(_localctx, 8, SQLParser::RuleDeleteQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(89);
    match(SQLParser::T__8);
    setState(90);
    tableName();
    setState(92);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__16) {
      setState(91);
      whereClause();
    }
    setState(94);
    match(SQLParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UpdateQueryContext ------------------------------------------------------------------

SQLParser::UpdateQueryContext::UpdateQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::TableNameContext* SQLParser::UpdateQueryContext::tableName() {
  return getRuleContext<SQLParser::TableNameContext>(0);
}

SQLParser::ColumnContext* SQLParser::UpdateQueryContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

SQLParser::ValueContext* SQLParser::UpdateQueryContext::value() {
  return getRuleContext<SQLParser::ValueContext>(0);
}

SQLParser::WhereClauseContext* SQLParser::UpdateQueryContext::whereClause() {
  return getRuleContext<SQLParser::WhereClauseContext>(0);
}


size_t SQLParser::UpdateQueryContext::getRuleIndex() const {
  return SQLParser::RuleUpdateQuery;
}

void SQLParser::UpdateQueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUpdateQuery(this);
}

void SQLParser::UpdateQueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUpdateQuery(this);
}


std::any SQLParser::UpdateQueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitUpdateQuery(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::UpdateQueryContext* SQLParser::updateQuery() {
  UpdateQueryContext *_localctx = _tracker.createInstance<UpdateQueryContext>(_ctx, getState());
  enterRule(_localctx, 10, SQLParser::RuleUpdateQuery);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(96);
    match(SQLParser::T__9);
    setState(97);
    tableName();
    setState(98);
    match(SQLParser::T__10);
    setState(99);
    column();
    setState(100);
    match(SQLParser::T__11);
    setState(101);
    value();
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__16) {
      setState(102);
      whereClause();
    }
    setState(105);
    match(SQLParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateIndexContext ------------------------------------------------------------------

SQLParser::CreateIndexContext::CreateIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::IndexNameContext* SQLParser::CreateIndexContext::indexName() {
  return getRuleContext<SQLParser::IndexNameContext>(0);
}

SQLParser::TableNameContext* SQLParser::CreateIndexContext::tableName() {
  return getRuleContext<SQLParser::TableNameContext>(0);
}

SQLParser::ColumnContext* SQLParser::CreateIndexContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}


size_t SQLParser::CreateIndexContext::getRuleIndex() const {
  return SQLParser::RuleCreateIndex;
}

void SQLParser::CreateIndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateIndex(this);
}

void SQLParser::CreateIndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateIndex(this);
}


std::any SQLParser::CreateIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitCreateIndex(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::CreateIndexContext* SQLParser::createIndex() {
  CreateIndexContext *_localctx = _tracker.createInstance<CreateIndexContext>(_ctx, getState());
  enterRule(_localctx, 12, SQLParser::RuleCreateIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(SQLParser::T__12);
    setState(108);
    indexName();
    setState(109);
    match(SQLParser::T__13);
    setState(110);
    tableName();
    setState(111);
    match(SQLParser::T__1);
    setState(112);
    column();
    setState(113);
    match(SQLParser::T__2);
    setState(114);
    match(SQLParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertColumnsContext ------------------------------------------------------------------

SQLParser::InsertColumnsContext::InsertColumnsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::ColumnContext *> SQLParser::InsertColumnsContext::column() {
  return getRuleContexts<SQLParser::ColumnContext>();
}

SQLParser::ColumnContext* SQLParser::InsertColumnsContext::column(size_t i) {
  return getRuleContext<SQLParser::ColumnContext>(i);
}


size_t SQLParser::InsertColumnsContext::getRuleIndex() const {
  return SQLParser::RuleInsertColumns;
}

void SQLParser::InsertColumnsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInsertColumns(this);
}

void SQLParser::InsertColumnsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInsertColumns(this);
}


std::any SQLParser::InsertColumnsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitInsertColumns(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::InsertColumnsContext* SQLParser::insertColumns() {
  InsertColumnsContext *_localctx = _tracker.createInstance<InsertColumnsContext>(_ctx, getState());
  enterRule(_localctx, 14, SQLParser::RuleInsertColumns);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(116);
    column();
    setState(121);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__14) {
      setState(117);
      match(SQLParser::T__14);
      setState(118);
      column();
      setState(123);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnsContext ------------------------------------------------------------------

SQLParser::ColumnsContext::ColumnsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::ColumnContext *> SQLParser::ColumnsContext::column() {
  return getRuleContexts<SQLParser::ColumnContext>();
}

SQLParser::ColumnContext* SQLParser::ColumnsContext::column(size_t i) {
  return getRuleContext<SQLParser::ColumnContext>(i);
}


size_t SQLParser::ColumnsContext::getRuleIndex() const {
  return SQLParser::RuleColumns;
}

void SQLParser::ColumnsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumns(this);
}

void SQLParser::ColumnsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumns(this);
}


std::any SQLParser::ColumnsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitColumns(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ColumnsContext* SQLParser::columns() {
  ColumnsContext *_localctx = _tracker.createInstance<ColumnsContext>(_ctx, getState());
  enterRule(_localctx, 16, SQLParser::RuleColumns);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(133);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__15: {
        enterOuterAlt(_localctx, 1);
        setState(124);
        match(SQLParser::T__15);
        break;
      }

      case SQLParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(125);
        column();
        setState(130);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLParser::T__14) {
          setState(126);
          match(SQLParser::T__14);
          setState(127);
          column();
          setState(132);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnContext ------------------------------------------------------------------

SQLParser::ColumnContext::ColumnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::ColumnContext::ID() {
  return getToken(SQLParser::ID, 0);
}


size_t SQLParser::ColumnContext::getRuleIndex() const {
  return SQLParser::RuleColumn;
}

void SQLParser::ColumnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn(this);
}

void SQLParser::ColumnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn(this);
}


std::any SQLParser::ColumnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitColumn(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ColumnContext* SQLParser::column() {
  ColumnContext *_localctx = _tracker.createInstance<ColumnContext>(_ctx, getState());
  enterRule(_localctx, 18, SQLParser::RuleColumn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(SQLParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableNameContext ------------------------------------------------------------------

SQLParser::TableNameContext::TableNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::TableNameContext::ID() {
  return getToken(SQLParser::ID, 0);
}


size_t SQLParser::TableNameContext::getRuleIndex() const {
  return SQLParser::RuleTableName;
}

void SQLParser::TableNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTableName(this);
}

void SQLParser::TableNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTableName(this);
}


std::any SQLParser::TableNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitTableName(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::TableNameContext* SQLParser::tableName() {
  TableNameContext *_localctx = _tracker.createInstance<TableNameContext>(_ctx, getState());
  enterRule(_localctx, 20, SQLParser::RuleTableName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(SQLParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexNameContext ------------------------------------------------------------------

SQLParser::IndexNameContext::IndexNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::IndexNameContext::ID() {
  return getToken(SQLParser::ID, 0);
}


size_t SQLParser::IndexNameContext::getRuleIndex() const {
  return SQLParser::RuleIndexName;
}

void SQLParser::IndexNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexName(this);
}

void SQLParser::IndexNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexName(this);
}


std::any SQLParser::IndexNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitIndexName(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::IndexNameContext* SQLParser::indexName() {
  IndexNameContext *_localctx = _tracker.createInstance<IndexNameContext>(_ctx, getState());
  enterRule(_localctx, 22, SQLParser::RuleIndexName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(SQLParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereClauseContext ------------------------------------------------------------------

SQLParser::WhereClauseContext::WhereClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::ConditionContext* SQLParser::WhereClauseContext::condition() {
  return getRuleContext<SQLParser::ConditionContext>(0);
}


size_t SQLParser::WhereClauseContext::getRuleIndex() const {
  return SQLParser::RuleWhereClause;
}

void SQLParser::WhereClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhereClause(this);
}

void SQLParser::WhereClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhereClause(this);
}


std::any SQLParser::WhereClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitWhereClause(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::WhereClauseContext* SQLParser::whereClause() {
  WhereClauseContext *_localctx = _tracker.createInstance<WhereClauseContext>(_ctx, getState());
  enterRule(_localctx, 24, SQLParser::RuleWhereClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(141);
    match(SQLParser::T__16);
    setState(142);
    condition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrderByClauseContext ------------------------------------------------------------------

SQLParser::OrderByClauseContext::OrderByClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::ColumnContext* SQLParser::OrderByClauseContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}


size_t SQLParser::OrderByClauseContext::getRuleIndex() const {
  return SQLParser::RuleOrderByClause;
}

void SQLParser::OrderByClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrderByClause(this);
}

void SQLParser::OrderByClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrderByClause(this);
}


std::any SQLParser::OrderByClauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitOrderByClause(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::OrderByClauseContext* SQLParser::orderByClause() {
  OrderByClauseContext *_localctx = _tracker.createInstance<OrderByClauseContext>(_ctx, getState());
  enterRule(_localctx, 26, SQLParser::RuleOrderByClause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(SQLParser::T__17);
    setState(145);
    column();
    setState(147);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__18

    || _la == SQLParser::T__19) {
      setState(146);
      _la = _input->LA(1);
      if (!(_la == SQLParser::T__18

      || _la == SQLParser::T__19)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

SQLParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::OrConditionContext* SQLParser::ConditionContext::orCondition() {
  return getRuleContext<SQLParser::OrConditionContext>(0);
}


size_t SQLParser::ConditionContext::getRuleIndex() const {
  return SQLParser::RuleCondition;
}

void SQLParser::ConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCondition(this);
}

void SQLParser::ConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCondition(this);
}


std::any SQLParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ConditionContext* SQLParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 28, SQLParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    orCondition();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OrConditionContext ------------------------------------------------------------------

SQLParser::OrConditionContext::OrConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::AndConditionContext *> SQLParser::OrConditionContext::andCondition() {
  return getRuleContexts<SQLParser::AndConditionContext>();
}

SQLParser::AndConditionContext* SQLParser::OrConditionContext::andCondition(size_t i) {
  return getRuleContext<SQLParser::AndConditionContext>(i);
}

std::vector<tree::TerminalNode *> SQLParser::OrConditionContext::OR() {
  return getTokens(SQLParser::OR);
}

tree::TerminalNode* SQLParser::OrConditionContext::OR(size_t i) {
  return getToken(SQLParser::OR, i);
}


size_t SQLParser::OrConditionContext::getRuleIndex() const {
  return SQLParser::RuleOrCondition;
}

void SQLParser::OrConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrCondition(this);
}

void SQLParser::OrConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrCondition(this);
}


std::any SQLParser::OrConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitOrCondition(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::OrConditionContext* SQLParser::orCondition() {
  OrConditionContext *_localctx = _tracker.createInstance<OrConditionContext>(_ctx, getState());
  enterRule(_localctx, 30, SQLParser::RuleOrCondition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(151);
    andCondition();
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::OR) {
      setState(152);
      match(SQLParser::OR);
      setState(153);
      andCondition();
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AndConditionContext ------------------------------------------------------------------

SQLParser::AndConditionContext::AndConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::BaseConditionContext *> SQLParser::AndConditionContext::baseCondition() {
  return getRuleContexts<SQLParser::BaseConditionContext>();
}

SQLParser::BaseConditionContext* SQLParser::AndConditionContext::baseCondition(size_t i) {
  return getRuleContext<SQLParser::BaseConditionContext>(i);
}

std::vector<tree::TerminalNode *> SQLParser::AndConditionContext::AND() {
  return getTokens(SQLParser::AND);
}

tree::TerminalNode* SQLParser::AndConditionContext::AND(size_t i) {
  return getToken(SQLParser::AND, i);
}


size_t SQLParser::AndConditionContext::getRuleIndex() const {
  return SQLParser::RuleAndCondition;
}

void SQLParser::AndConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndCondition(this);
}

void SQLParser::AndConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndCondition(this);
}


std::any SQLParser::AndConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitAndCondition(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::AndConditionContext* SQLParser::andCondition() {
  AndConditionContext *_localctx = _tracker.createInstance<AndConditionContext>(_ctx, getState());
  enterRule(_localctx, 32, SQLParser::RuleAndCondition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    baseCondition();
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::AND) {
      setState(160);
      match(SQLParser::AND);
      setState(161);
      baseCondition();
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BaseConditionContext ------------------------------------------------------------------

SQLParser::BaseConditionContext::BaseConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::ConditionContext* SQLParser::BaseConditionContext::condition() {
  return getRuleContext<SQLParser::ConditionContext>(0);
}

SQLParser::ColumnValueConditionContext* SQLParser::BaseConditionContext::columnValueCondition() {
  return getRuleContext<SQLParser::ColumnValueConditionContext>(0);
}


size_t SQLParser::BaseConditionContext::getRuleIndex() const {
  return SQLParser::RuleBaseCondition;
}

void SQLParser::BaseConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBaseCondition(this);
}

void SQLParser::BaseConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBaseCondition(this);
}


std::any SQLParser::BaseConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitBaseCondition(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::BaseConditionContext* SQLParser::baseCondition() {
  BaseConditionContext *_localctx = _tracker.createInstance<BaseConditionContext>(_ctx, getState());
  enterRule(_localctx, 34, SQLParser::RuleBaseCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(167);
        match(SQLParser::T__1);
        setState(168);
        condition();
        setState(169);
        match(SQLParser::T__2);
        break;
      }

      case SQLParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(171);
        columnValueCondition();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnValueConditionContext ------------------------------------------------------------------

SQLParser::ColumnValueConditionContext::ColumnValueConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::ColumnContext* SQLParser::ColumnValueConditionContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

SQLParser::OperatorContext* SQLParser::ColumnValueConditionContext::operator_() {
  return getRuleContext<SQLParser::OperatorContext>(0);
}

SQLParser::ValueContext* SQLParser::ColumnValueConditionContext::value() {
  return getRuleContext<SQLParser::ValueContext>(0);
}


size_t SQLParser::ColumnValueConditionContext::getRuleIndex() const {
  return SQLParser::RuleColumnValueCondition;
}

void SQLParser::ColumnValueConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumnValueCondition(this);
}

void SQLParser::ColumnValueConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumnValueCondition(this);
}


std::any SQLParser::ColumnValueConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitColumnValueCondition(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ColumnValueConditionContext* SQLParser::columnValueCondition() {
  ColumnValueConditionContext *_localctx = _tracker.createInstance<ColumnValueConditionContext>(_ctx, getState());
  enterRule(_localctx, 36, SQLParser::RuleColumnValueCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    column();
    setState(175);
    operator_();
    setState(176);
    value();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorContext ------------------------------------------------------------------

SQLParser::OperatorContext::OperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SQLParser::OperatorContext::getRuleIndex() const {
  return SQLParser::RuleOperator;
}

void SQLParser::OperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperator(this);
}

void SQLParser::OperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperator(this);
}


std::any SQLParser::OperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitOperator(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::OperatorContext* SQLParser::operator_() {
  OperatorContext *_localctx = _tracker.createInstance<OperatorContext>(_ctx, getState());
  enterRule(_localctx, 38, SQLParser::RuleOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 65015808) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableValuesContext ------------------------------------------------------------------

SQLParser::TableValuesContext::TableValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::TableValueContext *> SQLParser::TableValuesContext::tableValue() {
  return getRuleContexts<SQLParser::TableValueContext>();
}

SQLParser::TableValueContext* SQLParser::TableValuesContext::tableValue(size_t i) {
  return getRuleContext<SQLParser::TableValueContext>(i);
}


size_t SQLParser::TableValuesContext::getRuleIndex() const {
  return SQLParser::RuleTableValues;
}

void SQLParser::TableValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTableValues(this);
}

void SQLParser::TableValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTableValues(this);
}


std::any SQLParser::TableValuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitTableValues(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::TableValuesContext* SQLParser::tableValues() {
  TableValuesContext *_localctx = _tracker.createInstance<TableValuesContext>(_ctx, getState());
  enterRule(_localctx, 40, SQLParser::RuleTableValues);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(180);
    tableValue();
    setState(185);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__14) {
      setState(181);
      match(SQLParser::T__14);
      setState(182);
      tableValue();
      setState(187);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableValueContext ------------------------------------------------------------------

SQLParser::TableValueContext::TableValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SQLParser::ValueContext* SQLParser::TableValueContext::value() {
  return getRuleContext<SQLParser::ValueContext>(0);
}

tree::TerminalNode* SQLParser::TableValueContext::TYPE() {
  return getToken(SQLParser::TYPE, 0);
}


size_t SQLParser::TableValueContext::getRuleIndex() const {
  return SQLParser::RuleTableValue;
}

void SQLParser::TableValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTableValue(this);
}

void SQLParser::TableValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTableValue(this);
}


std::any SQLParser::TableValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitTableValue(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::TableValueContext* SQLParser::tableValue() {
  TableValueContext *_localctx = _tracker.createInstance<TableValueContext>(_ctx, getState());
  enterRule(_localctx, 42, SQLParser::RuleTableValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    value();
    setState(189);
    match(SQLParser::TYPE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValuesContext ------------------------------------------------------------------

SQLParser::ValuesContext::ValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SQLParser::ValueContext *> SQLParser::ValuesContext::value() {
  return getRuleContexts<SQLParser::ValueContext>();
}

SQLParser::ValueContext* SQLParser::ValuesContext::value(size_t i) {
  return getRuleContext<SQLParser::ValueContext>(i);
}


size_t SQLParser::ValuesContext::getRuleIndex() const {
  return SQLParser::RuleValues;
}

void SQLParser::ValuesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValues(this);
}

void SQLParser::ValuesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValues(this);
}


std::any SQLParser::ValuesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitValues(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ValuesContext* SQLParser::values() {
  ValuesContext *_localctx = _tracker.createInstance<ValuesContext>(_ctx, getState());
  enterRule(_localctx, 44, SQLParser::RuleValues);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    value();
    setState(196);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__14) {
      setState(192);
      match(SQLParser::T__14);
      setState(193);
      value();
      setState(198);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ValueContext ------------------------------------------------------------------

SQLParser::ValueContext::ValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SQLParser::ValueContext::ID() {
  return getToken(SQLParser::ID, 0);
}

tree::TerminalNode* SQLParser::ValueContext::STRING() {
  return getToken(SQLParser::STRING, 0);
}

tree::TerminalNode* SQLParser::ValueContext::NUMBER() {
  return getToken(SQLParser::NUMBER, 0);
}


size_t SQLParser::ValueContext::getRuleIndex() const {
  return SQLParser::RuleValue;
}

void SQLParser::ValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterValue(this);
}

void SQLParser::ValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SQLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitValue(this);
}


std::any SQLParser::ValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SQLVisitor*>(visitor))
    return parserVisitor->visitValue(this);
  else
    return visitor->visitChildren(this);
}

SQLParser::ValueContext* SQLParser::value() {
  ValueContext *_localctx = _tracker.createInstance<ValueContext>(_ctx, getState());
  enterRule(_localctx, 46, SQLParser::RuleValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 7516192768) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void SQLParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  sqlParserInitialize();
#else
  ::antlr4::internal::call_once(sqlParserOnceFlag, sqlParserInitialize);
#endif
}
