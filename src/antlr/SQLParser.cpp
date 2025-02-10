
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
      "query", "selectQuery", "insertQuery", "deleteQuery", "updateQuery", 
      "columns", "column", "tableName", "whereClause", "orderByClause", 
      "condition", "operator", "values", "value"
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
  	4,1,26,112,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,1,0,
  	1,0,1,0,3,0,33,8,0,1,1,1,1,1,1,1,1,1,1,3,1,40,8,1,1,1,3,1,43,8,1,1,1,
  	1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,3,3,58,8,3,1,3,1,3,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,3,4,69,8,4,1,4,1,4,1,5,1,5,1,5,1,5,5,5,77,8,
  	5,10,5,12,5,80,9,5,3,5,82,8,5,1,6,1,6,1,7,1,7,1,8,1,8,1,8,1,9,1,9,1,9,
  	3,9,94,8,9,1,10,1,10,1,10,1,10,1,11,1,11,1,12,1,12,1,12,5,12,105,8,12,
  	10,12,12,12,108,9,12,1,13,1,13,1,13,0,0,14,0,2,4,6,8,10,12,14,16,18,20,
  	22,24,26,0,3,1,0,16,17,2,0,11,11,18,22,1,0,23,25,108,0,32,1,0,0,0,2,34,
  	1,0,0,0,4,46,1,0,0,0,6,54,1,0,0,0,8,61,1,0,0,0,10,81,1,0,0,0,12,83,1,
  	0,0,0,14,85,1,0,0,0,16,87,1,0,0,0,18,90,1,0,0,0,20,95,1,0,0,0,22,99,1,
  	0,0,0,24,101,1,0,0,0,26,109,1,0,0,0,28,33,3,2,1,0,29,33,3,4,2,0,30,33,
  	3,6,3,0,31,33,3,8,4,0,32,28,1,0,0,0,32,29,1,0,0,0,32,30,1,0,0,0,32,31,
  	1,0,0,0,33,1,1,0,0,0,34,35,5,1,0,0,35,36,3,10,5,0,36,37,5,2,0,0,37,39,
  	3,14,7,0,38,40,3,16,8,0,39,38,1,0,0,0,39,40,1,0,0,0,40,42,1,0,0,0,41,
  	43,3,18,9,0,42,41,1,0,0,0,42,43,1,0,0,0,43,44,1,0,0,0,44,45,5,3,0,0,45,
  	3,1,0,0,0,46,47,5,4,0,0,47,48,3,14,7,0,48,49,5,5,0,0,49,50,5,6,0,0,50,
  	51,3,24,12,0,51,52,5,7,0,0,52,53,5,3,0,0,53,5,1,0,0,0,54,55,5,8,0,0,55,
  	57,3,14,7,0,56,58,3,16,8,0,57,56,1,0,0,0,57,58,1,0,0,0,58,59,1,0,0,0,
  	59,60,5,3,0,0,60,7,1,0,0,0,61,62,5,9,0,0,62,63,3,14,7,0,63,64,5,10,0,
  	0,64,65,3,12,6,0,65,66,5,11,0,0,66,68,3,26,13,0,67,69,3,16,8,0,68,67,
  	1,0,0,0,68,69,1,0,0,0,69,70,1,0,0,0,70,71,5,3,0,0,71,9,1,0,0,0,72,82,
  	5,12,0,0,73,78,3,12,6,0,74,75,5,13,0,0,75,77,3,12,6,0,76,74,1,0,0,0,77,
  	80,1,0,0,0,78,76,1,0,0,0,78,79,1,0,0,0,79,82,1,0,0,0,80,78,1,0,0,0,81,
  	72,1,0,0,0,81,73,1,0,0,0,82,11,1,0,0,0,83,84,5,23,0,0,84,13,1,0,0,0,85,
  	86,5,23,0,0,86,15,1,0,0,0,87,88,5,14,0,0,88,89,3,20,10,0,89,17,1,0,0,
  	0,90,91,5,15,0,0,91,93,3,12,6,0,92,94,7,0,0,0,93,92,1,0,0,0,93,94,1,0,
  	0,0,94,19,1,0,0,0,95,96,3,12,6,0,96,97,3,22,11,0,97,98,3,26,13,0,98,21,
  	1,0,0,0,99,100,7,1,0,0,100,23,1,0,0,0,101,106,3,26,13,0,102,103,5,13,
  	0,0,103,105,3,26,13,0,104,102,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,
  	106,107,1,0,0,0,107,25,1,0,0,0,108,106,1,0,0,0,109,110,7,2,0,0,110,27,
  	1,0,0,0,9,32,39,42,57,68,78,81,93,106
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
    setState(32);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(28);
        selectQuery();
        break;
      }

      case SQLParser::T__3: {
        enterOuterAlt(_localctx, 2);
        setState(29);
        insertQuery();
        break;
      }

      case SQLParser::T__7: {
        enterOuterAlt(_localctx, 3);
        setState(30);
        deleteQuery();
        break;
      }

      case SQLParser::T__8: {
        enterOuterAlt(_localctx, 4);
        setState(31);
        updateQuery();
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
  enterRule(_localctx, 2, SQLParser::RuleSelectQuery);
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
    setState(34);
    match(SQLParser::T__0);
    setState(35);
    columns();
    setState(36);
    match(SQLParser::T__1);
    setState(37);
    tableName();
    setState(39);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__13) {
      setState(38);
      whereClause();
    }
    setState(42);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__14) {
      setState(41);
      orderByClause();
    }
    setState(44);
    match(SQLParser::T__2);
   
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
  enterRule(_localctx, 4, SQLParser::RuleInsertQuery);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(SQLParser::T__3);
    setState(47);
    tableName();
    setState(48);
    match(SQLParser::T__4);
    setState(49);
    match(SQLParser::T__5);
    setState(50);
    values();
    setState(51);
    match(SQLParser::T__6);
    setState(52);
    match(SQLParser::T__2);
   
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
  enterRule(_localctx, 6, SQLParser::RuleDeleteQuery);
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
    setState(54);
    match(SQLParser::T__7);
    setState(55);
    tableName();
    setState(57);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__13) {
      setState(56);
      whereClause();
    }
    setState(59);
    match(SQLParser::T__2);
   
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
  enterRule(_localctx, 8, SQLParser::RuleUpdateQuery);
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
    setState(61);
    match(SQLParser::T__8);
    setState(62);
    tableName();
    setState(63);
    match(SQLParser::T__9);
    setState(64);
    column();
    setState(65);
    match(SQLParser::T__10);
    setState(66);
    value();
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__13) {
      setState(67);
      whereClause();
    }
    setState(70);
    match(SQLParser::T__2);
   
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
  enterRule(_localctx, 10, SQLParser::RuleColumns);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SQLParser::T__11: {
        enterOuterAlt(_localctx, 1);
        setState(72);
        match(SQLParser::T__11);
        break;
      }

      case SQLParser::ID: {
        enterOuterAlt(_localctx, 2);
        setState(73);
        column();
        setState(78);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SQLParser::T__12) {
          setState(74);
          match(SQLParser::T__12);
          setState(75);
          column();
          setState(80);
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
  enterRule(_localctx, 12, SQLParser::RuleColumn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
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
  enterRule(_localctx, 14, SQLParser::RuleTableName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
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
  enterRule(_localctx, 16, SQLParser::RuleWhereClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(87);
    match(SQLParser::T__13);
    setState(88);
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
  enterRule(_localctx, 18, SQLParser::RuleOrderByClause);
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
    setState(90);
    match(SQLParser::T__14);
    setState(91);
    column();
    setState(93);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SQLParser::T__15

    || _la == SQLParser::T__16) {
      setState(92);
      _la = _input->LA(1);
      if (!(_la == SQLParser::T__15

      || _la == SQLParser::T__16)) {
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
  enterRule(_localctx, 20, SQLParser::RuleCondition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    column();
    setState(96);
    operator_();
    setState(97);
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
  enterRule(_localctx, 22, SQLParser::RuleOperator);
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
    setState(99);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8128512) != 0))) {
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
  enterRule(_localctx, 24, SQLParser::RuleValues);
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
    setState(101);
    value();
    setState(106);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SQLParser::T__12) {
      setState(102);
      match(SQLParser::T__12);
      setState(103);
      value();
      setState(108);
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
  enterRule(_localctx, 26, SQLParser::RuleValue);
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
    setState(109);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 58720256) != 0))) {
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
