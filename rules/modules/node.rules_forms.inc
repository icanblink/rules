<?php

/**
 * @file Rules configuration forms for the node module
 */

/**
 *  Check for content types - Configuration form
 */
function rules_condition_content_is_type_form($settings, &$form) {
  $form['settings']['type'] = array(
    '#type' => 'select',
    '#title' => t('Content types'),
    '#options' => node_get_types('names'),
    '#multiple' => TRUE,
    '#default_value' => isset($settings['type']) ? $settings['type'] : array(),
    '#required' => TRUE,
  );
}

/**
 * Action node publish configuration form
 */
function rules_action_node_publish_form($settings, &$form) {
  $form['settings']['published'] = array(
    '#type' => 'checkbox',
    '#title' => t('Published'),
    '#default_value' => isset($settings['published']) ? $settings['published'] : 0,
  );
}

/**
 * Action node promote configuration form
 */
function rules_action_node_promote_form($settings, &$form) {
  $form['settings']['promote'] = array(
    '#type' => 'checkbox',
    '#title' => t('Promoted to front page'),
    '#default_value' => isset($settings['promote']) ? $settings['promote'] : 0,
  );
}

/**
 * Action node sticky configuration form
 */
function rules_action_node_sticky_form($settings, &$form) {
  $form['settings']['sticky'] = array(
    '#type' => 'checkbox',
    '#title' => t('Sticky at top of lists'),
    '#default_value' => isset($settings['sticky']) ? $settings['sticky'] : 0,
  );
}

/**
 * Action "Add a node" configuration form
 */
function rules_action_add_node_form($settings, &$form) {
  $form['settings']['type'] = array(
    '#type' => 'select',
    '#title' => t('Content type to be used'),
    '#options' => node_get_types('names'),
    '#default_value' => $settings['type'],
    '#description' => t('Select a single content type that will be created when this action is invoked.'),
    '#required' => TRUE,
  );
  $form['settings']['node_access'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create content only if the acting user (i.e. logged in user) has access rights to do so'),
    '#default_value' => $settings['node_access'],
    '#description' => t('Enable this in order for the system to check if the user has access rights for creating the
      required content. Note that even if the user arguments are set to \'content author \' the system will still check the \'acting user\'' ),
  );
  $form['settings']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $settings['title'],
    '#description' => t('Enter the title of the new created content.'),
    '#required' => TRUE,
  );
}

function rules_action_add_node_submit($form_id, $form_values) {
  //returns the needed settings
  $settings = rules_token_get_settings(array('title'), $form_values);
  $settings += array('type' => $form_values['type'], 'node_access' => $form_values['node_access']);
  return $settings;
}

/**
 * Action "Load a node" configuration form
 */
function rules_action_load_node_form($settings, &$form) {
  $form['settings']['nid'] = array(
    '#type' => 'textfield',
    '#title' => t('Content ID'),
    '#default_value' => isset($settings['nid']) ? $settings['nid'] : '',
    '#required' => TRUE,
  );
  $form['settings']['vid'] = array(
    '#type' => 'textfield',
    '#title' => t('Content Revision ID'),
    '#default_value' => isset($settings['vid']) ? $settings['vid'] : '',
    '#description' => t('If you want to load a specific revision, enter it\'s revision id. Else leave it empty to load the current revision.'),
  );
}