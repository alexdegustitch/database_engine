
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
      "operator", "tableValues", "tableValue", "values", "value"
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
  	4,1,30,169,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,0,1,0,
  	1,0,1,0,3,0,47,8,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,3,
  	2,61,8,2,1,2,3,2,64,8,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,3,3,74,8,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,3,4,85,8,4,1,4,1,4,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,3,5,96,8,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	7,1,7,1,7,5,7,112,8,7,10,7,12,7,115,9,7,1,8,1,8,1,8,1,8,5,8,121,8,8,10,
  	8,12,8,124,9,8,3,8,126,8,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,1,12,1,12,
  	1,13,1,13,1,13,3,13,140,8,13,1,14,1,14,1,14,1,14,1,15,1,15,1,16,1,16,
  	1,16,5,16,151,8,16,10,16,12,16,154,9,16,1,17,1,17,1,17,1,18,1,18,1,18,
  	5,18,162,8,18,10,18,12,18,165,9,18,1,19,1,19,1,19,0,0,20,0,2,4,6,8,10,
  	12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,3,1,0,19,20,2,0,12,12,21,
  	25,1,0,27,29,164,0,46,1,0,0,0,2,48,1,0,0,0,4,55,1,0,0,0,6,67,1,0,0,0,
  	8,81,1,0,0,0,10,88,1,0,0,0,12,99,1,0,0,0,14,108,1,0,0,0,16,125,1,0,0,
  	0,18,127,1,0,0,0,20,129,1,0,0,0,22,131,1,0,0,0,24,133,1,0,0,0,26,136,
  	1,0,0,0,28,141,1,0,0,0,30,145,1,0,0,0,32,147,1,0,0,0,34,155,1,0,0,0,36,
  	158,1,0,0,0,38,166,1,0,0,0,40,47,3,2,1,0,41,47,3,4,2,0,42,47,3,6,3,0,
  	43,47,3,8,4,0,44,47,3,10,5,0,45,47,3,12,6,0,46,40,1,0,0,0,46,41,1,0,0,
  	0,46,42,1,0,0,0,46,43,1,0,0,0,46,44,1,0,0,0,46,45,1,0,0,0,47,1,1,0,0,
  	0,48,49,5,1,0,0,49,50,3,20,10,0,50,51,5,2,0,0,51,52,3,32,16,0,52,53,5,
  	3,0,0,53,54,5,4,0,0,54,3,1,0,0,0,55,56,5,5,0,0,56,57,3,16,8,0,57,58,5,
  	6,0,0,58,60,3,20,10,0,59,61,3,24,12,0,60,59,1,0,0,0,60,61,1,0,0,0,61,
  	63,1,0,0,0,62,64,3,26,13,0,63,62,1,0,0,0,63,64,1,0,0,0,64,65,1,0,0,0,
  	65,66,5,4,0,0,66,5,1,0,0,0,67,68,5,7,0,0,68,73,3,20,10,0,69,70,5,2,0,
  	0,70,71,3,14,7,0,71,72,5,3,0,0,72,74,1,0,0,0,73,69,1,0,0,0,73,74,1,0,
  	0,0,74,75,1,0,0,0,75,76,5,8,0,0,76,77,5,2,0,0,77,78,3,36,18,0,78,79,5,
  	3,0,0,79,80,5,4,0,0,80,7,1,0,0,0,81,82,5,9,0,0,82,84,3,20,10,0,83,85,
  	3,24,12,0,84,83,1,0,0,0,84,85,1,0,0,0,85,86,1,0,0,0,86,87,5,4,0,0,87,
  	9,1,0,0,0,88,89,5,10,0,0,89,90,3,20,10,0,90,91,5,11,0,0,91,92,3,18,9,
  	0,92,93,5,12,0,0,93,95,3,38,19,0,94,96,3,24,12,0,95,94,1,0,0,0,95,96,
  	1,0,0,0,96,97,1,0,0,0,97,98,5,4,0,0,98,11,1,0,0,0,99,100,5,13,0,0,100,
  	101,3,22,11,0,101,102,5,14,0,0,102,103,3,20,10,0,103,104,5,2,0,0,104,
  	105,3,18,9,0,105,106,5,3,0,0,106,107,5,4,0,0,107,13,1,0,0,0,108,113,3,
  	18,9,0,109,110,5,15,0,0,110,112,3,18,9,0,111,109,1,0,0,0,112,115,1,0,
  	0,0,113,111,1,0,0,0,113,114,1,0,0,0,114,15,1,0,0,0,115,113,1,0,0,0,116,
  	126,5,16,0,0,117,122,3,18,9,0,118,119,5,15,0,0,119,121,3,18,9,0,120,118,
  	1,0,0,0,121,124,1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,126,1,0,0,
  	0,124,122,1,0,0,0,125,116,1,0,0,0,125,117,1,0,0,0,126,17,1,0,0,0,127,
  	128,5,27,0,0,128,19,1,0,0,0,129,130,5,27,0,0,130,21,1,0,0,0,131,132,5,
  	27,0,0,132,23,1,0,0,0,133,134,5,17,0,0,134,135,3,28,14,0,135,25,1,0,0,
  	0,136,137,5,18,0,0,137,139,3,18,9,0,138,140,7,0,0,0,139,138,1,0,0,0,139,
  	140,1,0,0,0,140,27,1,0,0,0,141,142,3,18,9,0,142,143,3,30,15,0,143,144,
  	3,38,19,0,144,29,1,0,0,0,145,146,7,1,0,0,146,31,1,0,0,0,147,152,3,34,
  	17,0,148,149,5,15,0,0,149,151,3,34,17,0,150,148,1,0,0,0,151,154,1,0,0,
  	0,152,150,1,0,0,0,152,153,1,0,0,0,153,33,1,0,0,0,154,152,1,0,0,0,155,
  	156,3,38,19,0,156,157,5,26,0,0,157,35,1,0,0,0,158,163,3,38,19,0,159,160,
  	5,15,0,0,160,162,3,38,19,0,161,159,1,0,0,0,162,165,1,0,0,0,163,161,1,
  	0,0,0,163,164,1,0,0,0,164,37,1,0,0,0,165,163,1,0,0,0,166,167,7,2,0,0,
  	167,39,1,0,0,0,12,46,60,63,73,84,95,113,122,125,139,152,163
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
    setState(46);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(40);
        createQuery();
        break;
      }

      case SQLParser::T__4: {
        enterOuterAlt(_localctx, 2);
        setState(41);
        selectQuery();
        break;
      }

      case SQLParser::T__6: {
        enterOuterAlt(_localctx, 3);
        setState(42);
        insertQuery();
        break;
      }

      case SQLParser::T__8: {
        enterOuterAlt(_localctx, 4);
        setState(43);
        deleteQuery();
        break;
      }

      case SQLParser::T__9: {
        enterOuterAlt(_localctx, 5);
        setState(44);
        updateQuery();
        break;
      }

      case SQLParser::T__12: {
        enterOuterAlt(_localctx, 6);
        setState(45);
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
    setState(48);
    match(SQLParser::T__0);
    setState(49);
    tableName();
    setState(50);
    match(SQLParser::T__1);
    setState(51);
    tableValues();
    setState(52);
    match(SQLParser::T__2);
    setState(53);
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
    setState(55);
    match(SQLParser::T__4);
    setState(56);
    columns();
    setState(57);
    match(SQLParser::T__5);
    setState(58);
    tableName();
    setState(60);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__16) {
      setState(59);
      whereClause();
    }
    setState(63);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__17) {
      setState(62);
      orderByClause();
    }
    setState(65);
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
    setState(67);
    match(SQLParser::T__6);
    setState(68);
    tableName();
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__1) {
      setState(69);
      match(SQLParser::T__1);
      setState(70);
      insertColumns();
      setState(71);
      match(SQLParser::T__2);
    }
    setState(75);
    match(SQLParser::T__7);
    setState(76);
    match(SQLParser::T__1);
    setState(77);
    values();
    setState(78);
    match(SQLParser::T__2);
    setState(79);
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
    setState(81);
    match(SQLParser::T__8);
    setState(82);
    tableName();
    setState(84);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__16) {
      setState(83);
      whereClause();
    }
    setState(86);
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
    setState(88);
    match(SQLParser::T__9);
    setState(89);
    tableName();
    setState(90);
    match(SQLParser::T__10);
    setState(91);
    column();
    setState(92);
    match(SQLParser::T__11);
    setState(93);
    value();
    setState(95);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__16) {
      setState(94);
      whereClause();
    }
    setState(97);
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
    setState(99);
    match(SQLParser::T__12);
    setState(100);
    indexName();
    setState(101);
    match(SQLParser::T__13);
    setState(102);
    tableName();
    setState(103);
    match(SQLParser::T__1);
    setState(104);
    column();
    setState(105);
    match(SQLParser::T__2);
    setState(106);
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
    setState(108);
    column();
    setState(113);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__14) {
      setState(109);
      match(SQLParser::T__14);
      setState(110);
      column();
      setState(115);
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
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__15: {
        enterOuterAlt(_localctx, 1);
        setState(116);
        match(SQLParser::T__15);
        break;
      }

      case SQLParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(117);
        column();
        setState(122);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLParser::T__14) {
          setState(118);
          match(SQLParser::T__14);
          setState(119);
          column();
          setState(124);
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
    setState(127);
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
    setState(129);
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
    setState(131);
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
    setState(133);
    match(SQLParser::T__16);
    setState(134);
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
    setState(136);
    match(SQLParser::T__17);
    setState(137);
    column();
    setState(139);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__18

    || _la == SQLParser::T__19) {
      setState(138);
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

SQLParser::ColumnContext* SQLParser::ConditionContext::column() {
  return getRuleContext<SQLParser::ColumnContext>(0);
}

SQLParser::OperatorContext* SQLParser::ConditionContext::operator_() {
  return getRuleContext<SQLParser::OperatorContext>(0);
}

SQLParser::ValueContext* SQLParser::ConditionContext::value() {
  return getRuleContext<SQLParser::ValueContext>(0);
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
    setState(141);
    column();
    setState(142);
    operator_();
    setState(143);
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
  enterRule(_localctx, 30, SQLParser::RuleOperator);
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
    setState(145);
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
  enterRule(_localctx, 32, SQLParser::RuleTableValues);
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
    setState(147);
    tableValue();
    setState(152);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__14) {
      setState(148);
      match(SQLParser::T__14);
      setState(149);
      tableValue();
      setState(154);
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
  enterRule(_localctx, 34, SQLParser::RuleTableValue);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    value();
    setState(156);
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
  enterRule(_localctx, 36, SQLParser::RuleValues);
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
    setState(158);
    value();
    setState(163);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__14) {
      setState(159);
      match(SQLParser::T__14);
      setState(160);
      value();
      setState(165);
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
  enterRule(_localctx, 38, SQLParser::RuleValue);
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
    setState(166);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 939524096) != 0))) {
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
