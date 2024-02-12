CREATE DATABASE IF NOT EXISTS workersdb;
USE workersdb;

CREATE TABLE IF NOT EXISTS `workers` (
  `id` integer unsigned PRIMARY KEY,
  `full_name` varchar(60) NOT NULL,
  `email` varchar(120) UNIQUE NOT NULL,
  `contact` bigint unsigned UNIQUE NOT NULL COMMENT 'should be checked that length is 10 digits',
  `secondary_contact` bigint unsigned UNIQUE COMMENT 'should be checked that length is 10 digits',
  `address` text NOT NULL,
  `locality` integer unsigned NOT NULL,
  `district` integer unsigned NOT NULL,
  `state` integer unsigned NOT NULL,
  `adhar_no` bigint unsigned UNIQUE NOT NULL COMMENT 'should be checked that length is 12 digits',
  `age` tinyint unsigned NOT NULL,
  `gender` tinyint unsigned NOT NULL COMMENT 'either male-0 or female-1 or other-2',
  `qualification` tinyint unsigned NOT NULL,
  `work_exp` tinyint unsigned NOT NULL,
  `previous_work` varchar(255),
  `expected_salary` integer unsigned NOT NULL COMMENT 'as of per month',
  `expected_daily_wage` smallint unsigned NOT NULL,
  `work_hours` tinyint unsigned NOT NULL,
  `skills` integer unsigned,
  `description` varchar(500),
  `extra_condition` varchar(500)
);

CREATE TABLE IF NOT EXISTS `skills` (
  `id` integer unsigned PRIMARY KEY,
  `name` varchar(20) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS `worker_skills` (
  `id` integer unsigned PRIMARY KEY,
  `worker` integer unsigned NOT NULL,
  `skill` integer unsigned NOT NULL
);

CREATE TABLE IF NOT EXISTS `customers` (
  `id` integer unsigned PRIMARY KEY,
  `full_name` varchar(60) NOT NULL,
  `email` varchar(120) UNIQUE NOT NULL,
  `contact` bigint unsigned UNIQUE NOT NULL COMMENT 'should be checked that length is 10 digits',
  `address` text NOT NULL,
  `locality` integer unsigned NOT NULL,
  `district` integer unsigned NOT NULL,
  `state` integer unsigned NOT NULL
);

CREATE TABLE IF NOT EXISTS `localities` (
  `id` integer unsigned PRIMARY KEY,
  `name` varchar(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS `districts` (
  `id` integer unsigned PRIMARY KEY,
  `name` varchar(60) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS `states` (
  `id` integer unsigned PRIMARY KEY,
  `name` varchar(60) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS `qualifications` (
  `id` tinyint unsigned PRIMARY KEY,
  `name` varchar(255) UNIQUE NOT NULL
);

ALTER TABLE `workers` ADD FOREIGN KEY (`qualification`) REFERENCES `qualifications` (`id`);

ALTER TABLE `workers` ADD FOREIGN KEY (`locality`) REFERENCES `localities` (`id`);

ALTER TABLE `workers` ADD FOREIGN KEY (`district`) REFERENCES `districts` (`id`);

ALTER TABLE `workers` ADD FOREIGN KEY (`state`) REFERENCES `states` (`id`);

ALTER TABLE `workers` ADD FOREIGN KEY (`skills`) REFERENCES `worker_skills` (`id`);

ALTER TABLE `worker_skills` ADD FOREIGN KEY (`worker`) REFERENCES `workers` (`id`);

ALTER TABLE `worker_skills` ADD FOREIGN KEY (`skill`) REFERENCES `skills` (`id`);

ALTER TABLE `customers` ADD FOREIGN KEY (`locality`) REFERENCES `localities` (`id`);

ALTER TABLE `customers` ADD FOREIGN KEY (`district`) REFERENCES `districts` (`id`);

ALTER TABLE `customers` ADD FOREIGN KEY (`state`) REFERENCES `states` (`id`);
