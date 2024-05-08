import {View, Text, StyleSheet, TextInput} from 'react-native';
import React from 'react';
import Icon from 'react-native-vector-icons/FontAwesome5';

const Location = () => {
  return (
    <View style={styles.container}>
      <View>
        <View style={styles.inputContainer}>
          <View style={styles.inputText}>
            <Icon name="facebook" size={24} />
            <Text style={styles.text}>Rajabazar Topsia, Kolkata</Text>
          </View>
          <View style={styles.leftIcon}>
            <Icon name="home" color="gray" size={24} />
          </View>
        </View>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    backgroundColor: '#355efc',
    paddingHorizontal: 10,
    paddingVertical: 10,
  },
  inputContainer: {
    flexDirection: 'row',
    alignItems: 'center',
    paddingVertical: 6,
    paddingHorizontal: 10,
    backgroundColor: 'white',
    borderRadius: 4,
    justifyContent: 'space-between',
  },
  inputText: {
    flexDirection: 'row',
    alignItems: 'center',
  },
  text: {
    marginLeft: 8,
    fontSize: 14,
  },
  leftIcon: {
    marginRight: 5,
  },
});

export default Location;
