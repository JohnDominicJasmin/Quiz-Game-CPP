#include "trueorfalsequestions.h"
#include <QString>
trueOrfalseQuestions::trueOrfalseQuestions()
{

}

QString trueOrfalseQuestions::getQuestion(int index){
  return questions[index];
}
QString trueOrfalseQuestions::getExplanation(int index){
  return explanations[index];
}
char trueOrfalseQuestions::getAnswers(int index){
  return answers[index];
}
QString trueOrfalseQuestions::getLivesPicture(){
  return livesPicture;
}
trueOrfalseQuestions::~trueOrfalseQuestions(){

}
