import {View, Text, StyleSheet, TextInput} from 'react-native';
import React from 'react';
import Icon from 'react-native-vector-icons/Ionicons';

const Location = () => {
  return (
    <View style={styles.container}>
      <View>
        <View style={styles.inputContainer}>
          <View style={styles.inputText}>
            <Icon name="location-outline" size={25} color="#bfc0c0" />
            <Text style={styles.text}>Rajabazar Topsia, Kolkata</Text>
          </View>
          <View style={styles.leftIcon}>
            <Icon name="filter-outline" color="#bfc0c0" size={20} />
          </View>
        </View>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    // backgroundColor: '#355efc',
    paddingHorizontal: 10,
    // paddingVertical: 10,
  },
  inputContainer: {
    flexDirection: 'row',
    alignItems: 'center',
    paddingVertical: 10,
    paddingHorizontal: 10,
    backgroundColor: 'white',
    borderRadius: 50,
    justifyContent: 'space-between',
    // borderWidth: 1,
    // borderColor: '#cccc',
    elevation: 3,
  },
  inputText: {
    flexDirection: 'row',
    alignItems: 'center',
    color: '#4f5d75',
  },
  text: {
    marginLeft: 8,
    fontSize: 14,
  },
  leftIcon: {
    marginRight: 0,
  },
});

export default Location;
