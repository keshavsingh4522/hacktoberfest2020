import { StatusBar } from 'expo-status-bar';
import React from 'react';
import { StyleSheet, Text, View, TouchableOpacity, Button, TextInput} from 'react-native';

export default function App() {
  const [text, onChangeText] = React.useState("Useless Text");
  const [number, onChangeNumber] = React.useState(null);
  const withdrawMoney = number * 0.2;
  const withdrawable = number - withdrawMoney;



  return (

    <View style={styles.container}>

      <View style={styles.calcbox}>
        <Text style={styles.heading}> Fiverr Calculator</Text>
        <TextInput
        style={styles.input}
        onChangeText={onChangeNumber}
        value={number}
        placeholder="Enter Your Earned Money"
        keyboardType="numeric"
      />

      <Text style={styles.heading}>Withdraw</Text>

      <View style={styles.withdrawbox}>
      <Text style={styles.heading}>${withdrawable}</Text>
      </View>

      <TouchableOpacity >

      {/* <Button 
            title="Find"
            color="lightgreen"
            accessibilityLabel="Tap This Button To Calculate Fiverr Commission In Your Earning."
          /> */}
        
        <StatusBar style="auto" />
      </TouchableOpacity>

      </View>
     
    </View>
  );
}

const styles = StyleSheet.create({

  
  container: {
    flex: 1,
    backgroundColor: 'lightgreen',
    alignItems: 'center',
    justifyContent: 'center',
  },


  calcbox:{
    color:'white',
    justifyContent: 'center',
    alignItems: 'center',
    width:250,
    height:400,
    backgroundColor:'#ffff',
 
  },

  heading:{
     color:'grey',
    textAlign: 'center',
    fontSize:20,
    fontFamily: 'monospace',
    margin: 10,
    
  },

  input: {
    height: 40,
    margin: 12,
    borderWidth: 1,
    padding: 10,
  },

  withdrawbox:{
    minWidth:100,
    minHeight:50,
    backgroundColor:'#f1f1f1',
    marginTop:20,
    // marginBottom:50,
 
  },

  
});
