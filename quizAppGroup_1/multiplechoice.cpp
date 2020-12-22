#include "multiplechoice.h"
#include<QMessageBox>
multiplechoice::multiplechoice()
{

}



QString multiplechoice::getLivesLeftPicture(){
  return liveLeftPicture;
}
QString multiplechoice::getDefaultColor_ofButton(){
  return defaultColorOfButtons;
}
QString multiplechoice::getGreenButton(){
  return GreenButton;
}
QString multiplechoice::getRedButton(){
  return RedButton;
}
QString multiplechoice::getlcdDisplayNumberRedColor(){
  return lcdDisplayNumberRedColor;
}
QString multiplechoice::getlcdDisplayDefaultColor(){
  return lcdDisplayNumberDefaultColor;
}
int multiplechoice::getIndexOfQuestionIs(){

  srand(time(0));
  return rand()%200;;
}




QString multiplechoice::getGeographyQuestion(int index){
return geographyQuestion[index];
}
QString multiplechoice::getGeographyChoices(int column,int row){
  return geographyChoice[column][row];
}
char multiplechoice::getGeographyAnswers(int index){
  return geographyAnswers[index];
}

///////////////////
QString multiplechoice::getAnimalsQuestions(int index){
  return animalsQuestions[index];
}
QString multiplechoice::getAnimalsChoices(int column, int row){
  return AnimalsChoice[column][row];
}
char multiplechoice::getAnimalsAnswers(int index){
  return animalAnswers[index];
}


QString multiplechoice::getHistoryQuestions(int index){
  return historyQuestion[index];
}
QString multiplechoice::getHistoryChoices(int column, int row){
  return historyChoices[column][row];
}
char multiplechoice::getHistoryAnswers(int indexnumber){
  return historyAnswer[indexnumber];
}


QString multiplechoice::getHumanitiesQuestion(int index){
  return humanitiesQuestion[index];
}
QString multiplechoice::getHumanitiesChoices(int column, int row){
  return humanitiesChoices[column][row];
}
char multiplechoice::getHumanitiesAnswers(int indexnumber){
  return humanitiesAnswer[indexnumber];
}


QString multiplechoice::getTechnologyQuestions(int index){
  return technologyQuestions[index];
}
QString multiplechoice::getTechnologyChoices(int column, int row){
  return technologyChoices[column][row];
}
char multiplechoice::getTechnologyAnswers(int indexnumber){
  return technologyAnswer[indexnumber];
}


QString multiplechoice::getWorldQuestions(int index){
  return worldQuestions[index];
}
QString multiplechoice::getWorldChoices(int column, int row){
  return worldChoices[column][row];
}
char multiplechoice::getWorldAnswers(int indexnumber){
  return worldAnswer[indexnumber];
}


QString multiplechoice::getMusicQuestion(int index){
  return musicQuestion[index];
}
QString multiplechoice::getMusicChoices(int column, int row){
  return musicChoices[column][row];
}
char multiplechoice::getMusicAnswer(int indexnumber){
  return musicAnswer[indexnumber];
}


QString multiplechoice::getSportsQuestion(int index){
  return sportsQuestions[index];
}
QString multiplechoice::getSportsChoices(int column, int row){
  return sportsChoices[column][row];
}
char multiplechoice::getSportsAnswer(int indexnumber){
  return sportsAnswer[indexnumber];
}


QString multiplechoice::getRandomQuestions(int index){
  return randomQuestions[index];
}
QString multiplechoice::getRandomChoices(int col, int row){
  return randomChoices[col][row];
}
char multiplechoice::getRandomAnswers(int index){
  return randomAnswer[index];
}

QString multiplechoice::getScienceQuestions(int index){
  return scienceQuestion[index];
}
QString multiplechoice::getScienceChoices(int col, int row){
  return scienceChoices[col][row];
}
char multiplechoice::getScienceAnswers(int index){
  return scienceAnswer[index];
}


multiplechoice::~multiplechoice(){

}















