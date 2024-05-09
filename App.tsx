import {View, Text, ScrollView} from 'react-native';
import React from 'react';
import {NavigationContainer} from '@react-navigation/native';
import 'react-native-gesture-handler';
import Auth from './src/navigators/Auth/Auth';
import {StatusBar} from 'react-native';

const App = () => {
  return (
    <NavigationContainer>
      <Auth />
      <StatusBar animated={true} backgroundColor="lightgray" />
    </NavigationContainer>
  );
};

export default App;
