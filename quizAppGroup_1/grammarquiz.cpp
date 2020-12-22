#include "grammarquiz.h"

GrammarQuiz::GrammarQuiz()
{

}
QString GrammarQuiz::getQuestion(int index){
  return questions[index];
}
QString GrammarQuiz::getChoices(int col, int row){
  return choices[col][row];
}
char GrammarQuiz::getAnswers(int index){
  return answer[index];
}
QString GrammarQuiz::getDefaultButtonColor(){
  return defaultcolor;
}
QString GrammarQuiz::getGreenButtonColor(){
  return greenColorOfButton;
}
QString GrammarQuiz::getRedButtonColor(){
  return redColorOfButton;
}
QString GrammarQuiz::getLivesBackground(){
  return livesBackground;
}

QString GrammarQuiz::getQuestionBonusQuiz(int index){
  return question_1[index];
}
QString GrammarQuiz::getChoicesBonusQuiz(int col, int row){
  return choices_1[col][row];
}
char GrammarQuiz::getAnswerBonusQuiz(int index){
  return answer_1[index];
}
GrammarQuiz::~GrammarQuiz(){

}
