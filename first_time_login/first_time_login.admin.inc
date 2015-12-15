<?php

/**
 * @file
 * Admin configuration file of First time login module.
 */

/**
 * Implements first_time_login_form().
 */
function first_time_login_form($form, &$form_state) {
  $site_name = variable_get('site_name');
  $form['first_time_login_config_days'] = array(
    '#type' => 'textfield',
    '#element_validate' => array('element_validate_integer_positive'),
    '#title' => t('Enter the number of days.'),
    '#required' => TRUE,
    '#default_value' => variable_get('first_time_login_config_days'),
    '#description' => t('Numeric field - enter number of days.
      For example: Enter 60 for 60 days / 2 Months. </br>
      User who has not updated their account since the above mentioned days,
      will be prompted to updated their account after login.'),
  );
  $form['new_user_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the welcome message for the newly registered users.'),
    '#required' => TRUE,
    '#default_value' => variable_get('first_time_login_new_user_message'),
    '#description' => t('Text field - enter message.
      For example: Welcome to the @site_name. </br>
      Allowed tokens: @user, @site_name and @created_date'),
  );
  $form['update_user_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the reminder message for the users </br>who have not updated their profile since the above configured number of days.'),
    '#required' => TRUE,
    '#default_value' => variable_get('first_time_login_update_user_message'),
    '#description' => t('Text field - enter message.
      For example: @user, please update your account. </br>
      Allowed tokens: @user, @site_name and @updated_date'),
  );
  return system_settings_form($form);
}
