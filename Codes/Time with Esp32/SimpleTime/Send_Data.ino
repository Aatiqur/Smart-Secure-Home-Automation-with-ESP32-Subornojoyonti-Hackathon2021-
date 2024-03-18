void sendData(String Name)
{
  String t = getTimee();
  String d = getDatee();
  long randNumber;
  randNumber = random(0, 100000);

  String nm = String(randNumber);

  String path = "Users/654321/Attendance/" + nm;

  Firebase.setString(firebaseData, path + "/Time", t);
  Firebase.setString(firebaseData, path +  "/Date", d);
  Firebase.setString(firebaseData, path + "/Name", Name);

}
