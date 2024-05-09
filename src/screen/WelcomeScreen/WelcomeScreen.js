import {View, Text, StyleSheet, Image, TouchableOpacity} from 'react-native';
import React from 'react';
import {useNavigation} from '@react-navigation/native';

const WelcomeScreen = () => {
  const navigation = useNavigation();

  return (
    <View style={styles.container}>
      <Image
        source={{
          uri: 'https://cdn.sanity.io/images/kts928pd/production/b46a6970cc0f064f5ba5d6370077c7f2e18dbb0f-1200x630.png',
        }}
        style={{
          height: '20%',
          width: '100%',
        }}
      />
      <TouchableOpacity
        onPress={() => {
          navigation.navigate('TabNavigation');
        }}
        style={styles.button}>
        <Image
          source={{
            uri: 'https://upload.wikimedia.org/wikipedia/commons/thumb/c/c1/Google_%22G%22_logo.svg/2048px-Google_%22G%22_logo.svg.png',
          }}
          style={{
            height: 25,
            width: 25,
            marginRight: 10,
          }}
        />
        <Text style={styles.loginText}>Login with Google</Text>
      </TouchableOpacity>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    backgroundColor: 'white',
    height: '100%',
    width: '100%',
    alignItems: 'center',
    justifyContent: 'center',
    flex: 1,
  },
  button: {
    flexDirection: 'row',
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: '#4f5d75',
    width: '90%',
    paddingVertical: 12,
    textAlign: 'center',
    borderRadius: 50,
    marginTop: 50,
    elevation: 15,
  },
  loginText: {
    textAlign: 'center',
    fontSize: 16,
    color: 'white',
    fontWeight: '500',
  },
});
export default WelcomeScreen;
