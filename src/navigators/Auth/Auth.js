import {createStackNavigator} from '@react-navigation/stack';
import React from 'react';
import Home from '../../screen/Home/Home';
import WelcomeScreen from '../../screen/WelcomeScreen/WelcomeScreen';

const Stack = createStackNavigator();

function Auth() {
  return (
    <Stack.Navigator
      screenOptions={{
        headerShown: false,
      }}>
      <Stack.Screen name="Login" component={WelcomeScreen} />
      <Stack.Screen name="Home" component={Home} />
    </Stack.Navigator>
  );
}

export default Auth;
